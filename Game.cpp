#include <GL/glew.h>
#include <GL/glut.h>
#include "./Headers/Game.h"

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

    // Load Models
    std::vector<Model *> models;

    // Load Grass Model
    Model *grassModel = new Model("./Assets/Grass/grass.json", "./Assets/Grass/grass.png", "grass");

    // Load Dirt Model
    Model *dirtModel = new Model("./Assets/Dirt/dirt.json", "./Assets/Dirt/dirt.png", "dirt");

    models.push_back(grassModel);
    models.push_back(dirtModel);

    MapSpawner *mapSpawner = new MapSpawner(models);

    mapSpawner->setHeight(10);
    mapSpawner->setWidth(20);

    map = mapSpawner->spawn();

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
