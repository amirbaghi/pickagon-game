#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "../Subject.h"
#include "../Command/Command.h"

class Game;

class PhysicsEngine : public Subject
{
public:
    ~PhysicsEngine();

    // Instance Method
    static PhysicsEngine* instance(Game* game);

    // Update Method
    void update(Command& command);

private:
    // Private Constructor
    PhysicsEngine();
    PhysicsEngine(Game* game);

    // Game Object
    Game* game;
};

#endif