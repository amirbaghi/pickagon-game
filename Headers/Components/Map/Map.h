#ifndef MAP_H
#define MAP_H

#include <vector>
#include "../Actor/Tile.h"

class Map
{
public:
    Map();
    ~Map();

    // Getter
    std::vector<Tile *> getTiles();
    int getWidth();
    int getHeight();

    // Setter
    void setTiles(std::vector<Tile *> tiles);
    void setWidth(int width);
    void setHeight(int height);

    // Render
    void render();

    // Update
    void update();

    // TODO: Maybe make this class an observer and subscribe to the physics engine
    // and then propagate the events down to tiles

private:
    std::vector<Tile *> tiles_;

    int width_, height_;
};

#endif