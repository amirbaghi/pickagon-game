#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include "./Headers/Components/Model/Model.h"
#include "./Headers/JsonUtility.h"
#include "SOIL.h"

Model::Model()
{
}

Model::~Model()
{
}

Model::Model(const std::string &jsonFilename, const std::string &spriteSheetFilename, std::string modelName)
{
    this->modelName = modelName;
    load(jsonFilename, spriteSheetFilename);
}

void Model::load(const std::string &jsonFilename, const std::string &spriteSheetFilename)
{
    readFile(jsonFilename, spriteSheetFilename);
    initBuffers();
}

void Model::readFile(const std::string &jsonFilename, const std::string &spriteSheetFilename)
{

    std::string jsonString;

    std::ifstream is(jsonFilename);
    if (is.is_open())
    {
        std::stringstream buffer;
        buffer << is.rdbuf();
        jsonString = buffer.str();

        is.close();
    }
    else
    {
        return;
    }

    jsonData = Load(jsonString);

    frameCount = jsonData["frames"].size();
    tex_w = jsonData["meta"]["size"]["w"].ToInt();
    tex_h = jsonData["meta"]["size"]["h"].ToInt();

    texture_id = SOIL_load_OGL_texture(spriteSheetFilename.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void Model::initBuffers()
{
    glGenBuffers(1, &vertex_vbo_id);
    glGenBuffers(1, &texcoord_vbo_id);

    // Creating the face index vector for the quad
    for (int i = 0; i < 4; i++)
    {
        faces.push_back(i);
    }

    glGenBuffers(1, &element_vbo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_vbo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, faces.size() * sizeof(GLuint), &faces[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Model::getFrame(int i, int &x, int &y, int &w, int &h)
{
    std::string frameName = modelName + "_" + std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10) + ".png";

    auto frame = jsonData["frames"][frameName.c_str()]["frame"];

    x = frame["x"].ToInt();
    y = frame["y"].ToInt();
    w = frame["w"].ToInt();
    h = frame["h"].ToInt();
}

void Model::render(int frame)
{
    int x, y, w, h;
    getFrame(frame, x, y, w, h);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    vertices.clear();
    vertices.push_back(vertex(0 - w / 2, 0 - h / 2, 0));
    vertices.push_back(vertex(0 + w / 2, 0 - h / 2, 0));
    vertices.push_back(vertex(0 + w / 2, 0 + h / 2, 0));
    vertices.push_back(vertex(0 - w / 2, 0 + h / 2, 0));

    glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo_id);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_DYNAMIC_DRAW);
    glVertexPointer(3, GL_DOUBLE, 0, NULL);

    texCoord.clear();
    texCoord.push_back((float)x / tex_w);
    texCoord.push_back(1 - (float)(y + h) / tex_h);
    texCoord.push_back((float)(x + w) / tex_w);
    texCoord.push_back(1 - (float)(y + h) / tex_h);
    texCoord.push_back((float)(x + w) / tex_w);
    texCoord.push_back(1 - (float)y / tex_h);
    texCoord.push_back((float)x / tex_w);
    texCoord.push_back(1 - (float)y / tex_h);

    glBindBuffer(GL_ARRAY_BUFFER, texcoord_vbo_id);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &texCoord[0], GL_DYNAMIC_DRAW);
    glTexCoordPointer(2, GL_FLOAT, 0, NULL);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_vbo_id);
    glDrawElements(GL_QUADS, (faces.size() * sizeof(GLuint)) / 4, GL_UNSIGNED_INT, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisable(GL_TEXTURE_2D);
}
