#include <GL/glew.h>
#include <GL/glut.h>
#include "./Headers/Game.h"
#include "./Headers/Components/Command/PickCommand.h"

Game::Game()
{
}

Game::~Game()
{
    delete commandStream;
    delete physicsEngine;
    delete mapSpawner;
    delete map;
    delete player;
}

Game *Game::instance()
{
    static Game *instance = new Game();
    return instance;
}

void Game::initGame(int argc, char **argv)
{
    // Setting the start time for the game
    startTime = std::chrono::steady_clock::now();

    std::srand((unsigned int)std::time(NULL));

    // // Initializing the main modules of the game
    commandStream = CommandStream::instance();
    physicsEngine = PhysicsEngine::instance(this);
    RenderEngine::init(argc, argv, this);

    // Load Models and adding them to the map spawner's vector of models
    std::vector<Model *> models;

    Model *grassModel = new Model("./Assets/Grass/grass.json", "./Assets/Grass/grass.png", "grass");
    Model *dirtModel = new Model("./Assets/Dirt/dirt.json", "./Assets/Dirt/dirt.png", "dirt");
    Model *marsModel = new Model("./Assets/Mars/mars.json", "./Assets/Mars/mars.png", "mars");
    Model *sandModel = new Model("./Assets/Sand/sand.json", "./Assets/Sand/sand.png", "sand");
    Model *stoneModel = new Model("./Assets/Stone/stone.json", "./Assets/Stone/stone.png", "stone");
    Model *modernModel = new Model("./Assets/Modern/modern.json", "./Assets/Modern/modern.png", "modern");
    Model *scifiModel = new Model("./Assets/Sci-fi/scifi.json", "./Assets/Sci-fi/scifi.png", "scifi");

    double scaleRatio = 2.0;
    dirtModel->setScaleRatio(scaleRatio);
    grassModel->setScaleRatio(scaleRatio);
    marsModel->setScaleRatio(scaleRatio);
    sandModel->setScaleRatio(scaleRatio);
    stoneModel->setScaleRatio(scaleRatio);
    modernModel->setScaleRatio(scaleRatio);
    scifiModel->setScaleRatio(scaleRatio);

    models.push_back(sandModel);
    models.push_back(dirtModel);
    models.push_back(grassModel);
    models.push_back(modernModel);
    models.push_back(stoneModel);
    models.push_back(marsModel);
    models.push_back(scifiModel);

    MapSpawner *mapSpawner = new MapSpawner(models);

    mapSpawner->setWidthAndHeight(7);

    map = mapSpawner->spawn();

    // Subscribe the tiles to the physics engine
    std::vector<Tile *> tiles = map->getTiles();

    for (auto t : tiles)
    {
        physicsEngine->addObserver(t);
    }

    player = new Player();
}

int Game::mainLoop()
{
    glutMainLoop();
}

Map *Game::getMap()
{
    return map;
}

void Game::handleSelection(GLint hits, GLuint buffer[])
{
    // Process hits
    if (hits == 0)
    {
        return;
    }
    unsigned int i, j;
    GLuint names, *ptr, minZ, *ptrNames;

    ptr = (GLuint *)buffer;
    minZ = 0xffffffff;
    for (i = 0; i < hits; i++)
    {
        names = *ptr;
        ptr++;
        if (*ptr < minZ)
        {
            minZ = *ptr;
            ptrNames = ptr + 2;
        }
        ptr += names + 2;
    }
    ptr = ptrNames;

    PickCommand *pickCommand = new PickCommand();

    pickCommand->setName(*ptr);

    commandStream->pushCommand(pickCommand);

    Command *command = commandStream->popCommand();

    physicsEngine->handleCommand(*command);
}
