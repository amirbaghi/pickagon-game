#include "./Headers/Game.h"

Game::Game()
{
}

Game::~Game()
{
    delete renderEngine;
    delete commandStream;
    delete physicsEngine;
}

Game *Game::instance()
{
    static Game *instance = new Game();
    return instance;
}


void Game::initGame()
{
    // Setting the start time for the game
    startTime = std::chrono::steady_clock::now();

    std::srand((unsigned int)std::time(NULL));

    // Initializing the main modules of the game
    renderEngine = RenderEngine::instance(this);
    commandStream = CommandStream::instance();
    physicsEngine = PhysicsEngine::instance(this);

    // Subscribing to the physics engine

    // Creating and Loading models for squares and the board
    // And creating a spawner for the board, using the models
    // BoardModel *boardModel = new BoardModel();
    // SquareModel *squareModel = new SquareModel();
    // boardModel->load();
    // squareModel->load();
    // boardSpawner = new BoardSpawner(boardModel, squareModel);


    // Spawning the Board
    // board = boardSpawner->spawn();

}

void Game::mainLoop()
{

    do
    {

        // Get command from Player
        // Command *command = aiEngine->generateMove(currentTurn);

        // Push it in the command stream
        // commandStream->pushCommand(command);

        // Pop the most recent command
        // Command *recentCommand = commandStream->popCommand();

        // Update the game
        // physicsEngine->update(*recentCommand);

        // Delete the recent command
        // delete recentCommand;

    } while (true);
}

void Game::run()
{

    // Initialize the game for the first time
    this->initGame();

    // Running the game
    this->mainLoop();

}