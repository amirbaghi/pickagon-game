#include <random>
#include <ctime>
#include "./Headers/Components/Spawner/MapSpawner.h"
#include "./Headers/Components/Map/Map.h"
#include "./Headers/Components/State/TileState.h"
#include "./Headers/Components/State/UnselectedState.h"

MapSpawner::MapSpawner(std::vector<Model *> models) : Spawner(models)
{
}

MapSpawner::~MapSpawner()
{
}

int MapSpawner::getWidth()
{
    return width_;
}

int MapSpawner::getHeight()
{
    return height_;
}

void MapSpawner::setHeight(int height)
{
    height_ = height;
}

void MapSpawner::setWidth(int width)
{
    width_ = width;
}

Map *MapSpawner::spawn()
{

    std::srand(time(nullptr));

    Map *map = new Map();

    map->setHeight(height_);
    map->setWidth(width_);

    std::vector<Tile *> tiles;

    int count = 0;

    double x_offset = 30;
    double y_offset = 35 + (30.0 / cos(30.0 * M_PI / 180.0)) / 2.0;

    double current_x, current_y;

    for (int i = 0; i < map->getHeight(); i++)
    {
        current_y = 35 + i * y_offset;
        for (int j = 0; j < map->getWidth(); j++)
        {
            Tile *tile;
            TileState *tileState = new UnselectedState();
            if (j >= map->getWidth() / 2)
            {
                tile = new Tile(models[0], tileState);
            }
            else
            {
                tile = new Tile(models[1], tileState);
            }

            tile->setFrame(1 + (std::rand() % 16));
            tile->setName(count);
            ++count;

            if (i % 2 == 0)
            {
                current_x = 30 + j * 60;
            }
            else
            {
                current_x = 60 + j * 60;
            }

            tile->setPosition(vertex(current_x, current_y, 0.0));

            tiles.push_back(tile);
        }
    }

    map->setTiles(tiles);

    return map;
}