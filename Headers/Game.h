#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <chrono>
#include "./Components/Render/RenderEngine.h"
#include "./Components/Physics/PhysicsEngine.h"
#include "./Components/Command/CommandStream.h"

class Game
{
public:
    ~Game();

    // Instance Method
    static Game *instance();

    // Game initialization
    void initGame();

    // Game Main Loop
    void mainLoop();

    // Run the Game
    void run();

private:
    // Private Constructor
    Game();

    // Render Engine
    RenderEngine *renderEngine;

    // Command Stream
    CommandStream *commandStream;

    // Physics Engine
    PhysicsEngine *physicsEngine;

    // Spawners

    // Map

    // Start Time
    std::chrono::steady_clock::time_point startTime;

};

#endif
