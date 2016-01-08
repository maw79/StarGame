//
// Created by aaron on 1/7/16.
//

#ifndef OPENGL_PLAYER_H
#define OPENGL_PLAYER_H

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>

typedef struct{
    float x;
    float y;
}point2D;

class player {
protected:
public:
    point2D position;
    int speed;

    player();
    void set_position(float x, float y);
    point2D get_position();
    void accelerate();
    void decelerate();
    void Turn(bool LR);
    void draw_ship();
    void shoot();
};


#endif //OPENGL_PLAYER_H
