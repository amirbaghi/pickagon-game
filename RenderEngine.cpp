#include <GL/glew.h>
#include <iostream>
#include "./Headers/Components/Render/RenderEngine.h"
#include "./Headers/Game.h"

bool RenderEngine::isCameraMoving = false;
Direction RenderEngine::direction = UP;
Game *RenderEngine::game = nullptr;

double RenderEngine::x_camera_offset = 0;
double RenderEngine::y_camera_offset = 0;

double RenderEngine::size = 0;
double RenderEngine::width = 140;
double RenderEngine::height = 120;

RenderEngine::RenderEngine()
{
}

RenderEngine::~RenderEngine()
{
}

void RenderEngine::init(int argc, char **argv, Game *game)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Pickagon");

    RenderEngine::game = game;

    RenderEngine::height = 120.0 / 2.0;
    RenderEngine::width = 140.0 / 2.0;

    glewInit();

    glClearColor(0.0, 105.0 / 255.0, 148.0 / 255.0, 0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(render);
    glutReshapeFunc(resize);
    glutSpecialFunc(specialKeyboardFunction);
    glutSpecialUpFunc(specialUpKeyboardFunction);
    glutKeyboardFunc(keyboardFunction);
    glutMouseFunc(mouseFunction);
    glutTimerFunc(25, timer, 0);
}

void RenderEngine::render()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glMatrixMode(GL_MODELVIEW);

    Map *map = RenderEngine::game->getMap();

    map->render();

    glLoadName(-1);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glutSwapBuffers();
}

void RenderEngine::mouseFunction(int button, int state, int x, int y)
{
    GLuint selectBuf[BUFFSIZE];
    GLint hits;
    GLint viewport[4];
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    glGetIntegerv(GL_VIEWPORT, viewport);
    glSelectBuffer(BUFFSIZE, selectBuf);
    glRenderMode(GL_SELECT);

    glInitNames();
    glPushName(-1);

    // PICK MATRIX

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 0.05, 0.05, viewport);

    // ORIGINAL PROJECTION MATRIX

    auto w = glutGet(GLUT_WINDOW_WIDTH);
    auto h = glutGet(GLUT_WINDOW_HEIGHT);

    glOrtho(0, w + 1000, 0, h + 1000, 0.0, 3.0);

    gluLookAt(RenderEngine::x_camera_offset, RenderEngine::y_camera_offset, 2, RenderEngine::x_camera_offset, RenderEngine::y_camera_offset, 0, 0, 1, 0);

    // Render

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glMatrixMode(GL_MODELVIEW);

    Map *map = RenderEngine::game->getMap();

    map->render();

    glLoadName(-1);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glPopMatrix();

    glutSwapBuffers();

    // // Process Hits
    hits = glRenderMode(GL_RENDER);
    game->handleSelection(hits, selectBuf);
}

void RenderEngine::specialKeyboardFunction(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_DOWN:
        RenderEngine::isCameraMoving = true;
        RenderEngine::direction = DOWN;
        break;
    case GLUT_KEY_LEFT:
        RenderEngine::isCameraMoving = true;
        RenderEngine::direction = LEFT;
        break;
    case GLUT_KEY_RIGHT:
        RenderEngine::isCameraMoving = true;
        RenderEngine::direction = RIGHT;
        break;
    case GLUT_KEY_UP:
        RenderEngine::isCameraMoving = true;
        RenderEngine::direction = UP;
        break;
    default:
        break;
    }
}

void RenderEngine::specialUpKeyboardFunction(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_DOWN:
        RenderEngine::isCameraMoving = false;
        break;
    case GLUT_KEY_LEFT:
        RenderEngine::isCameraMoving = false;
        break;
    case GLUT_KEY_RIGHT:
        RenderEngine::isCameraMoving = false;
        break;
    case GLUT_KEY_UP:
        RenderEngine::isCameraMoving = false;
        break;
    default:
        break;
    }
}

void RenderEngine::keyboardFunction(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
    case 'Q':
        exit(0);
        break;
    }
}

void RenderEngine::resize(int w, int h)
{
    camera_config(w, h);
}

void RenderEngine::timer(int value)
{
    if (RenderEngine::isCameraMoving)
    {
        switch (RenderEngine::direction)
        {
        case UP:
            if (RenderEngine::y_camera_offset <= 700)
            {
                RenderEngine::y_camera_offset += 10.0;
            }
            break;
        case DOWN:
            if (RenderEngine::y_camera_offset >= -700)
            {

                RenderEngine::y_camera_offset -= 10.0;
            }
            break;
        case RIGHT:
            if (RenderEngine::x_camera_offset <= 700)
            {
                RenderEngine::x_camera_offset += 10.0;
            }
            break;
        case LEFT:
            if (RenderEngine::x_camera_offset >= -700)
            {
                RenderEngine::x_camera_offset -= 10.0;
            }
            break;

        default:
            break;
        }
    }

    auto w = glutGet(GLUT_WINDOW_WIDTH);
    auto h = glutGet(GLUT_WINDOW_HEIGHT);

    camera_config(w, h);

    glutTimerFunc(25, timer, value + 1);

    glutPostRedisplay();
}

void RenderEngine::camera_config(double w, double h)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w + 1000, 0, h + 1000, 0.0, 3.0);

    gluLookAt(RenderEngine::x_camera_offset, RenderEngine::y_camera_offset, 2, RenderEngine::x_camera_offset, RenderEngine::y_camera_offset, 0, 0, 1, 0);

    glViewport(0, 0, w, h);
}
