//
// Created by aaron on 1/10/16.
//

#ifndef OPENGL_CHUNK_H
#define OPENGL_CHUNK_H

#include "Stars.h"


class chunk {
public:
    int x;
    int y;
    Stars chunkd;
    chunk(int z, int w);
};


#endif //OPENGL_CHUNK_H
