
#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "../Direction.h"

class Game;

class RenderEngine
{
public:
    RenderEngine();
    ~RenderEngine();

    // Render Engine Properties
    static Game *game;

    static bool isCameraMoving;
    static Direction direction;

    static double x_camera_offset;
    static double y_camera_offset;

    // Init render engine
    static void init(int argc, char **argv, Game* game);

    // Method to for rendering
    static void render();

    // Mouse Function
    static void mouseFunction(int button, int state, int x, int y);

    // Special keyboard function
    static void specialKeyboardFunction(int key, int x, int y);

    // Special Up keyboard function
    static void specialUpKeyboardFunction(int key, int x, int y);

    // Keyboard function
    static void keyboardFunction(unsigned char key, int x, int y);

    // Resize method
    static void resize(int w, int h);

    // Timer Function
    static void timer(int value);

    // Camera Function
    static void camera_config(double w, double h);

};

#endif