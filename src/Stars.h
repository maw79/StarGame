//
// Created by aaron on 1/8/16.
//

#ifndef OPENGL_STARS_H
#define OPENGL_STARS_H

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>

class Stars {
private:
    bool StarS[200][200];
public:
    bool Debug;
    Stars();
    void Gen_Stars();
    void Display_Stars();
    void Read_Stars();
    void Move_Stars(int speed);
};


#endif //OPENGL_STARS_H
