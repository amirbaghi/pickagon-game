#include <random>
#include "./Headers/Utils.h"

float Utils::randomGenerator(int range)
{
    return (rand() % (range * 2)) - range;
}