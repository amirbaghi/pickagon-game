#ifndef MAPSPAWNER_H
#define MAPSPAWNER_H

#include "./Spawner.h"
#include "../Map/Map.h"

class MapSpawner : public Spawner
{
public:
    MapSpawner(std::vector<Model *> models);
    ~MapSpawner();

    int getWidth();
    int getHeight();

    void setWidth(int width);
    void setHeight(int height);

    // TODO: MIGHT NEED MODIFICATION
    Map *spawn();

private:
    int width_, height_;
};

#endif