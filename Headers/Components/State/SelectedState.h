#ifndef SELECTEDSTATE_H
#define SELECTEDSTATE_H

#include "./TileState.h"

class SelectedState: public TileState
{
public:
    SelectedState();
    ~SelectedState();

    virtual TileState* handleEvent(Tile& tile, Event event) override;
    void update(Tile& tile) override;
    void render(Tile& tile) override;
    
};



#endif