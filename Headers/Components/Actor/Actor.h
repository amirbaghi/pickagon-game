#ifndef ACTOR_H
#define ACTOR_H

#include "../Observer.h"
#include "../Model/Model.h"

class Actor : public Observer
{
public:
    Actor();
    Actor(Model *model);
    virtual ~Actor();

    // Model Getter
    Model *getModel();

    // Model Setter
    void setModel(Model * model);

    // Abstract Render Method
    virtual void render() = 0;

    // Abstract Update Method
    virtual void update() = 0;

protected:
    // Actor's Model
    Model *model;
};

#endif