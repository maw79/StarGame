/*
 * Made By: Aaron Riggs
 * Date: 1/7/16
 * Project: Space Game
 */

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>
#include "player.h"
#include "Stars.h"

void init();
void g_display();
void g_reshape(GLint width, GLint height);
void g_spKeyboard(int key, int x, int y);
void g_keyboard(unsigned char key, int x, int y);
void g_mouse(int button, int state, int x, int y);
void g_idle();

std::clock_t g_PreviousTicks;
std::clock_t g_CurrentTicks;

player ship;
Stars star;

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Space Game");

    init();

    glutDisplayFunc(g_display);
    glutReshapeFunc(g_reshape);
    glutSpecialFunc(g_spKeyboard);
    glutKeyboardFunc(g_keyboard);
    glutMouseFunc(g_mouse);
    glutIdleFunc(g_idle);
    glutMainLoop();
}

void init()
{
    std::cout << "openGL Init" << std::endl;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100,-100,100,-100,+100);

    ship.set_position(0,0);

    star.Gen_Stars();
    //star.Read_Stars();
}

void g_display()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,10,0,0,0,0,1,0);

    ship.draw_ship();

    star.Display_Stars();

    glutSwapBuffers();
}

void g_reshape(GLint width, GLint height)
{

}

void g_spKeyboard(int key, int x, int y)
{

}

void g_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27: // Esc
            glutLeaveMainLoop();
            break;
        case 119: // w
            ship.accelerate();
            break;
        case 115: // s
            ship.decelerate();
            break;
        case 97: // a
            ship.Turn(true);
            break;
        case 100: // d
            ship.Turn(false);
            break;
        case 32 : //space
            ship.shoot();
            break;
        default:break;
    }
}

void g_mouse(int button, int state, int x, int y)
{

}

void g_idle(void)
{
    g_CurrentTicks = std::clock();
    float deltaTicks = ( g_CurrentTicks - g_PreviousTicks );
    g_PreviousTicks = g_CurrentTicks;

    float fDeltaTime = deltaTicks / (float)CLOCKS_PER_SEC;

    //std::cout << "Time test :" << fDeltaTime << std::endl;

    ship.idle();

    glutPostRedisplay();
}