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
    Tile *getTile();

    // Setters
    void setTile(Tile *tile);

    // Execute command
    Event *execute();

private:
    // Picked Tile
    Tile *tile_;
};

#endif