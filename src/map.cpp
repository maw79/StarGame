//
// Created by aaron on 1/15/16.
//

#include "map.h"

map::map()
{
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            chunks[i][j] = chunk(i,j);
        }
    }
}
