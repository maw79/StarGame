//
// Created by aaron on 1/8/16.
//

#include "Stars.h"

Stars::Stars()
{
    if(Debug)
    {
        std::cout << "Stars constructor" << std::endl;
    }
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