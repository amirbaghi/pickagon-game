#ifndef DIAMONDSQUAREGENERATOR_H
#define DIAMONDSQUAREGENERATOR_H

// The functions needed for generating a height-map using the Diamond Square Generation Algorithm
namespace DiamondSquareGenerator
{
    void diamondSquareDiamondStep(double **Array, int x_width, int y_width, int x, int y, int reach, int &max);
    void diamondSquareSquareStep(double **Array, int x_width, int y_width, int x, int y, int reach, int &max);
    void diamondSquare(double **Array, int x_width, int y_width, int size, int &max);
    double **diamondSquareMapGenerator(int size);
}


#endif