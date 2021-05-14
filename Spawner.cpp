#include "./Headers/Components/Spawner/Spawner.h"


Spawner::Spawner(Model* model)
{
    this->model = model;
}

Spawner::~Spawner()
{
    delete model;
}