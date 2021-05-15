#ifndef UNSELECTEDSTATE_H
#define UNSELECTEDSTATE_H

#include "./TileState.h"

class UnselectedState : public TileState
{
public:
    UnselectedState();
    ~UnselectedState();

    virtual TileState *handleEvent(Tile &tile, Event event) override;
    void update(Tile &tile) override;
    void render(Tile &tile) override;
};

#endif