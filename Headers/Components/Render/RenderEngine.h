
#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <GL/glut.h>
#include "../Direction.h"

#define BUFFSIZE 2048

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

    static double size;
    static double width;
    static double height;

    // Init render engine
    static void init(int argc, char **argv, Game *game);

    // Method to for rendering
    static void render();

    // Select Method
    // static void select(GLint hits, GLuint buffer[]);

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