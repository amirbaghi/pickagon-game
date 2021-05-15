#include "./Headers/Components/Actor/Actor.h"

Actor::Actor(Model *model)
{
    this->model = model;
}

Actor::~Actor()
{
}

Model* Actor::getModel()
{
    return this->model;
}