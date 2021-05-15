#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <GL/glut.h>
#include "../../json.hpp"
#include "../vertex.h"
#include "../color4.h"

class Model
{
public:
    Model();
    Model(const std::string &jsonFilename, const std::string &spriteSheetFilename, std::string modelName);
    virtual ~Model();

    // Load method
    void load(const std::string &jsonFilename, const std::string &spriteSheetFilename);

    // Init Buffers Method
    virtual void initBuffers();

    // Render method
    virtual void render(int frame);

    // Get Frame Method
    virtual void getFrame(int i, int &x, int &y, int &w, int &h);

    // Read File method
    virtual void readFile(const std::string &jsonFilename, const std::string &spriteSheetFilename);

    // Scale Ratio Getter
    double getScaleRatio();

    // Scale Ratio Setter
    void setScaleRatio(double ratio);

    // OpenGL Properties for this model
    GLuint vertex_vbo_id, texcoord_vbo_id, element_vbo_id;
    GLuint texture_id, frameCount, tex_h, tex_w;

    std::string modelName;
    json::JSON jsonData;

private:
    std::vector<vertex> vertices;
    std::vector<GLfloat> texCoord;
    std::vector<GLuint> faces;
    std::vector<color4> colors;

    // The ratio by which the width and height of the texture is divided
    double scaleRatio;
};

#endif