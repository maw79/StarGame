//
// Created by aaron on 1/8/16.
//

#include "Stars.h"

Stars::Stars()
{
    std::cout << "Stars constructor" << std::endl;
    for(int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            StarS[i][j] = false;
        }
    }
}

void Stars::Gen_Stars()
{
    int star = 0;
    for(int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            star = (rand() % 500 + 1);
            if (star == 7)
            {
                StarS[i][j] = true;
                star = 0;
            }
        }
    }
}

void Stars::Display_Stars()
{
    glColor3f(1.0,1.0,1.0);
    for(int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            if(StarS[i][j])
            {
                glBegin(GL_POINTS);
                glVertex2f((i-100),(j-100));
                glEnd();
            }
        }
    }
}

void Stars::Read_Stars()
{
    std::cout << "Reading Star Locations" << std::endl;
    for(int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            if(StarS[i][j])
            {
                std::cout << "Star at [x:" << (i-100) << "  y:" << (j-100) << "]" << std::endl;
            }
        }
    }
}

void Stars::Move_Stars(int speed)
{
    if(speed != 0)
    {
        std::cout << "start clone" << std::endl;
        //clone start
        bool starClone[200][200];
        for(int i = 0; i < 200; i++)
        {
            for (int j = 0; j < 200; j++)
            {
                starClone[i][j] = StarS[i][j];
            }
        }
        for(int i = 0; i < 200; i++)
        {
            for (int j = 0; j < (200 - speed); j++)
            {
                StarS[i][j+speed] = starClone[i][j];
            }
        }
        for(int i = 0; i < 200; i++)
        {
            for (int j = 0; j < speed; ++j)
            {
                if ((rand() % 500 + 1) == 7)
                {
                    StarS[i][j] = true;
                }
            }
        }
    }
}
