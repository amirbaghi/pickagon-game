#ifndef MODEL_H
#define MODEL_H

class Model
{
public:
    Model();
    virtual ~Model();

    // Abstract load method
    virtual void load() = 0;

    // Abstract render method
    virtual void render() = 0;
};

#endif