#ifndef LABYRINTH_MAKER_H
#define LABYRINTH_MAKER_H

#include "Point.h"
#include "Cell.h"
#include "Labyrinth.h"
#include "NeighbourPoints.h"

namespace LabyrinthMaker {
    /*======================================================================
                          Initialization methods
    ========================================================================*/

    void generateMaze(const int size, Labyrinth *labyrinth, int startX, int startY);

    void generateMaze(Labyrinth *labyrinth, int sizeX, int sizeY, int startX, int startY);

    void generateMaze(Labyrinth *labyrinth, int size);


    void generateMaze(Labyrinth *labyrinth, int sizeX, int sizeY);

    /*======================================================================
                              Generation methods
    ========================================================================*/

    // This method take in the grid and a position and return the the indexes of the free neighbours at this position
    NeighbourPoints getFreeNeighbours(Labyrinth *labyrinth, Point position, int w, int h);

    // A cell is free if doesn't exist in the grid
    boolean isCellFree(Labyrinth *labyrinth, Point position);

    boolean isPointInsideGrid(Point point, int w, int h);

    void generateMazeRecursive(Labyrinth *labyrinth, Point position, int w, int h);

    void openLabyrinth(Labyrinth *labyrinth, int w, int h);

    namespace {
        extern Point directions[4];
    }
}

#endif // LABYRINTH_MAKER_H