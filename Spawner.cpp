#include "./Headers/Components/Spawner/Spawner.h"


Spawner::Spawner(std::vector<Model *> models)
{
    this->models = models;
}

Spawner::~Spawner()
{
    for (auto m : models)
    {
        delete m;
    }
}