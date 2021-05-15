#ifndef PICKCOMMAND_H
#define PICKCOMMAND_H

#include "./Command.h"
#include "../Actor/Tile.h"

class PickCommand : public Command
{
public:
    PickCommand();
    ~PickCommand();

    // Getters
    int getName();

    // Setters
    void setName(int name);

    // Execute command
    Event *execute();

private:
    // Name of the picked tile
    int name_;
};

#endif