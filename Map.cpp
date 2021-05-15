#include "./Headers/Components/Map/Map.h"

Map::Map()
{
}

Map::~Map()
{
    // Delete the tiles
    for (auto t : tiles_)
    {
        delete t;
    }
}

int Map::getWidth()
{
    return width_;
}

int Map::getHeight()
{
    return height_;
}

void Map::setHeight(int height)
{
    height_ = height;
}

void Map::setWidth(int width)
{
    width_ = width;
}

std::vector<Tile *> Map::getTiles()
{
    return tiles_;
}

void Map::setTiles(std::vector<Tile *> tiles)
{
    tiles_ = tiles;
}

void Map::render()
{
    for (auto t : tiles_)
    {
        t->render();
    }
}

void Map::update()
{
    for (auto t : tiles_)
    {
        t->update();
    }
}
