#include <cmath>
#include <random>
#include "./Headers/Components/Spawner/DiamondSquareGenerator.h"
#include "./Headers/Utils.h"

void DiamondSquareGenerator::diamondSquareDiamondStep(double **Array, int x_width, int y_width, int x, int y, int reach, int &max)
{
    int count = 0;
    float avg = 0.0f;
    if (x - reach >= 0)
    {
        avg += Array[x - reach][y];
        count++;
    }
    if (x + reach < x_width)
    {
        avg += Array[x + reach][y];
        count++;
    }
    if (y - reach >= 0)
    {
        avg += Array[x][y - reach];
        count++;
    }
    if (y + reach < y_width)
    {
        avg += Array[x][y + reach];
        count++;
    }
    avg += Utils::randomGenerator(reach);
    avg /= count;
    Array[x][y] = (int)avg;
    max = fmax(Array[x][y], max);
}

void DiamondSquareGenerator::diamondSquareSquareStep(double **Array, int x_width, int y_width, int x, int y, int reach, int &max)
{
    int count = 0;
    float avg = 0.0f;
    if (x - reach >= 0 && y - reach >= 0)
    {
        avg += Array[x - reach][y - reach];
        count++;
    }
    if (x - reach >= 0 && y + reach < y_width)
    {
        avg += Array[x - reach][y + reach];
        count++;
    }
    if (x + reach < x_width && y - reach >= 0)
    {
        avg += Array[x + reach][y - reach];
        count++;
    }
    if (x + reach < x_width && y + reach < y_width)
    {
        avg += Array[x + reach][y + reach];
        count++;
    }
    avg += Utils::randomGenerator(reach);
    avg /= count;
    Array[x][y] = round(avg);

    max = fmax(Array[x][y], max);
}

void DiamondSquareGenerator::diamondSquare(double **Array, int x_width, int y_width, int size, int &max)
{
    int half = size / 2;
    if (half < 1)
        return;

    for (int y = half; y < y_width; y += size)
        for (int x = half; x < x_width; x += size)
            diamondSquareSquareStep(Array, x_width, y_width, x % x_width, y % y_width, half, max);

    int col = 0;
    for (int x = 0; x < x_width; x += half)
    {
        col++;
        if (col % 2 == 1)
            for (int y = half; y < y_width; y += size)
                diamondSquareDiamondStep(Array, x_width, y_width, x % x_width, y % y_width, half, max);
        else
            for (int y = 0; y < y_width; y += size)
                diamondSquareDiamondStep(Array, x_width, y_width, x % x_width, y % y_width, half, max);
    }
    diamondSquare(Array, x_width, y_width, size / 2, max);
}

double **DiamondSquareGenerator::diamondSquareMapGenerator(int size)
{
    int x = size;
    int y = size;

    double **map = (double **)malloc(x * sizeof(double *));

    for (int i = 0; i < x; i++)
    {
        map[i] = (double *)malloc(y * sizeof(double *));
    }

    std::srand(time(NULL));

    map[0][0] = 1 + std::rand() % 20;
    map[0][x - 1] = 1 + std::rand() % 20;
    map[y - 1][0] = 1 + std::rand() % 20;
    map[y - 1][x - 1] = 1 + std::rand() % 20;

    int maxElement = fmax(map[0][0], fmax(map[0][x - 1], fmax(map[y - 1][0], map[y - 1][x - 1])));

    diamondSquare(map, x, y, x - 1, maxElement);

    // Normalize the array

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            map[i][j] /= maxElement;
        }
    }

    return map;
}