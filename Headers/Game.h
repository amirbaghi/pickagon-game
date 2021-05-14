#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <chrono>
#include "./Components/Render/RenderEngine.h"
#include "./Components/Physics/PhysicsEngine.h"
#include "./Components/Command/CommandStream.h"
#include "./Components/Spawner/MapSpawner.h"
#include "./Components/Map/Map.h"
#include "./Components/Player/Player.h"

class Game
{
public:
    ~Game();

    // Instance Method
    static Game *instance();

    // Getters
    Map* getMap();

    // Game initialization
    void initGame(int argc, char **argv);

    // Main Loop
    int mainLoop();

private:
    // Private Constructor
    Game();

    // Command Stream
    CommandStream *commandStream;

    // Physics Engine
    PhysicsEngine *physicsEngine;

    // Spawners
    MapSpawner* mapSpawner;

    // Map
    Map* map;

    // Player
    Player* player;

    // Start Time
    std::chrono::steady_clock::time_point startTime;
};

#endif
