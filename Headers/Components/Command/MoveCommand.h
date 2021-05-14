#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "./Command.h"
#include "../Direction.h"

class MoveCommand : public Command
{
public:
    MoveCommand();
    ~MoveCommand();

    // Getters
    Direction getDirection();

    // Setters
    void setDirection(Direction direction);

    // Execute command
    Event *execute();

private:
    Direction direction_;
};

#endif