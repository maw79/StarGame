//
// Created by aaron on 1/7/16.
//

#include "player.h"

player::player()
{
    std::cout << "Player constructor" << std::endl;
    position.x = 0.0;
    position.y = 0.0;
}

void player::set_position(float x, float y)
{
    position.x = x;
    position.y = y;
}

point2D player::get_position()
{
    return position;
}

void player::accelerate()
{
    speed++;
}

void player::decelerate()
{
    speed--;
}

//Left is true, right is false
void player::Turn(bool LR)
{
    if(LR)
    {
        //Turn Left
    }
    else
    {
        //Turn Right
    }
}

void player::draw_ship()
{
    glColor3f(1.0,1.0,1.0);

    glPushMatrix();
    glTranslatef(position.x, position.y, 0.0);
    glScalef(0.5, 0.5, 0.5);

    glBegin(GL_LINE_LOOP);
    glVertex2f( 10.0f, 20.0f);
    glVertex2f( 14.0f, 4.0f);
    glVertex2f( 12.0f, 6.0f);
    glVertex2f( 8.0f, 6.0f);
    glVertex2f( 6.0f, 4.0f);
    glEnd();

    glPointSize(2);
    glBegin(GL_POINTS);			// retro vertex points
    glVertex2f( 10.0f, 20.0f);
    glVertex2f( 14.0f, 4.0f);
    glVertex2f( 12.0f, 6.0f);
    glVertex2f( 8.0f, 6.0f);
    glVertex2f( 6.0f, 4.0f);
    glEnd();

    glPopMatrix();
}

void player::shoot()
{

}
