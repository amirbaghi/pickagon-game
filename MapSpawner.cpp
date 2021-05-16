#include <random>
#include <ctime>
#include <cmath>
#include "./Headers/Components/Spawner/MapSpawner.h"
#include "./Headers/Components/Spawner/DiamondSquareGenerator.h"
#include "./Headers/Components/Map/Map.h"
#include "./Headers/Components/State/TileState.h"
#include "./Headers/Components/State/UnselectedState.h"
#include "./Headers/Utils.h"

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

void MapSpawner::setWidthAndHeight(int n)
{
    width_ = pow(2, n) + 1;
    height_ = pow(2, n) + 1;
}

Map *MapSpawner::spawn()
{

    std::srand(time(nullptr));

    Map *map = new Map();

    map->setHeight(height_);
    map->setWidth(width_);

    std::vector<Tile *> tiles;

    int count = 0;
    double w = 120.0 / models[0]->getScaleRatio();
    double h = 140.0 / models[0]->getScaleRatio();

    double x_offset = w / 2.0;
    double y_offset = h / 2.0 + ((w / 2.0) / cos(30.0 * M_PI / 180.0)) / 2.0;

    double current_x, current_y;

    for (int i = 0; i < map->getHeight(); i++)
    {
        current_y = (h / 2.0) + i * y_offset;
        for (int j = 0; j < map->getWidth(); j++)
        {
            Tile *tile;
            TileState *tileState = new UnselectedState();
            tile = new Tile(tileState);
            tile->setName(count);
            ++count;

            if (i % 2 == 0)
            {
                current_x = w / 2.0 + j * w;
            }
            else
            {
                current_x = w + j * w;
            }

            tile->setPosition(vertex(current_x, current_y, 0.0));

            tiles.push_back(tile);
        }
    }

    // Texture assignment (First generate a height map using the diamond square map generator, then assign the textures based on the values,
    // the values returned by the generator are normalized)
    double **diamondMap = DiamondSquareGenerator::diamondSquareMapGenerator(width_);

    int index = 0;
    for (int i = 0; i < width_; i++)
    {
        for (int j = 0; j < height_; j++, index++)
        {
            Tile *tile = tiles[index];
            if (0 <= diamondMap[i][j] && diamondMap[i][j] < 0.2)
            {
                // Sand
                tile->setModel(models[0]);
                tile->setFrame((std::rand() % 17));
            }
            else if (0.2 <= diamondMap[i][j] && diamondMap[i][j] < 0.4)
            {
                // Dirt
                tile->setModel(models[1]);
                tile->setFrame(1 + (std::rand() % 17));
            }
            else if (0.4 <= diamondMap[i][j] && diamondMap[i][j] < 0.6)
            {
                // Grass
                tile->setModel(models[2]);
                tile->setFrame((std::rand() % 17));
            }
            else if (0.6 <= diamondMap[i][j] && diamondMap[i][j] < 0.7)
            {
                // Modern
                tile->setModel(models[3]);
                tile->setFrame((std::rand() % 13));
            }
            else if (0.7 <= diamondMap[i][j] && diamondMap[i][j] < 0.8)
            {
                // Stone
                tile->setModel(models[4]);
                tile->setFrame((std::rand() % 17));
            }
            else if (0.8 <= diamondMap[i][j] && diamondMap[i][j] < 0.9)
            {
                // Mars
                tile->setModel(models[5]);
                tile->setFrame((std::rand() % 17));
            }
            else if (0.9 <= diamondMap[i][j] && diamondMap[i][j] <= 1.0)
            {
                // Sci-fi
                tile->setModel(models[6]);
                tile->setFrame((std::rand() % 17));
            }
            else
            {
                // Sand
                tile->setModel(models[0]);
                tile->setFrame((std::rand() % 17));
            }
        }
    }

    map->setTiles(tiles);

    return map;
}
