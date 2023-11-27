#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "Cell.h"

struct Labyrinth {
    int w;
    int h;

    Cell grid[16][16];

    Labyrinth(int w, int h) {
        this->w = w;
        this->h = h;

        for (int x = 0; x < w; x++) {
            for (int y = 0; y < w; y++) {
                grid[x][y] = Cell();
            }
        }
    }
};

#endif // LABYRINTH_H