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

    // Set width and height to 2^n + 1
    void setWidthAndHeight(int n);
    
    Map *spawn();

private:
    int width_, height_;
};

#endif