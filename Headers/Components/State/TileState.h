#ifndef TILESTATE_H
#define TILESTATE_H

#include "../Actor/Tile.h"

class TileState
{
public:
    TileState();
    virtual ~TileState();


    virtual TileState* handleEvent(Tile& tile, Event event) = 0;
    virtual void enter(Tile& tile);
    virtual void update(Tile& tile);
    virtual void render(Tile& tile);
};


#endif