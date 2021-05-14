#ifndef UNSELECTEDSTATE_H
#define UNSELECTEDSTATE_H

#include "./TileState.h"

class UnselectedState: public TileState
{
public:
    UnselectedState();
    ~UnselectedState();

    virtual TileState* handleEvent(Tile& tile, Event event);
    void update(Tile& tile);
};



#endif