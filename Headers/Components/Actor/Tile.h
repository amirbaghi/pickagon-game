#ifndef TILE_H
#define TILE_H

#include "./Actor.h"
#include "../vertex.h"

class TileState;

class Tile : public Actor
{
public:
    Tile(Model *model, TileState *initialState);
    ~Tile();

    // Getters
    int getFrame();
    vertex getPosition();
    int getName();

    // Setters
    void setFrame(int frame);
    void setPosition(vertex position);
    void setName(int name);

    // Render method
    void render() override;

    // On Notify Method
    void onNotify(Event &event) override;

private:
    // Tile State
    TileState *tileState_;
    // Current position of the tile
    vertex position_;
    // Frame of the tile
    int frame;
    // Name of this tile (needed for OpenGL selection)
    int name_;

};

#endif