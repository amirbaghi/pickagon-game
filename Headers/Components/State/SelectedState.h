#ifndef SELECTEDSTATE_H
#define SELECTEDSTATE_H

#include "./TileState.h"

class SelectedState: public TileState
{
public:
    SelectedState();
    ~SelectedState();

    virtual TileState* handleEvent(Tile& tile, Event event);
    void update(Tile& tile);
};



#endif