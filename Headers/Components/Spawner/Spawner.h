 
#ifndef SPAWNER_H
#define SPAWNER_H

#include "../Actor/Actor.h"
#include "../Model/Model.h"

class Spawner
{
public:
    Spawner(std::vector<Model *> models);
    virtual ~Spawner();

    // // Abstract method for spawning
    // virtual Actor *spawn() {};

protected:
    // Models Associated with the class for this spawner
    std::vector<Model *> models;
};

#endif