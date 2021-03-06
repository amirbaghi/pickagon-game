#include <unistd.h>
#include "./Headers/Components/Physics/PhysicsEngine.h"
#include "./Headers/Components/Events/Event.h"
#include "./Headers/Game.h"

PhysicsEngine::PhysicsEngine()
{
}

PhysicsEngine::PhysicsEngine(Game *game)
{
    this->game_ = game;
}

PhysicsEngine::~PhysicsEngine()
{
}

PhysicsEngine *PhysicsEngine::instance(Game *game)
{
    static PhysicsEngine *instance = new PhysicsEngine(game);
    return instance;
}

void PhysicsEngine::handleCommand(Command &command)
{
    // Execute the command
    Event *event = command.execute();

    // Notify all the observers of the event that happened
    notify((*event));

    // Delete the event
    delete event;
}

void PhysicsEngine::update()
{
    Map *map = game_->getMap();

    map->update();
}