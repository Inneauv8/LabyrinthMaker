#include "LabyrinthMaker.h"

namespace LabyrinthMaker {
    /*======================================================================
                          Initialization methods
    ========================================================================*/

    void generateMaze(const int size, Labyrinth *labyrinth, int startX, int startY) {
        generateMaze(labyrinth, size, size, startX, startY);
    }

    void generateMaze(Labyrinth *labyrinth, int sizeX, int sizeY, int startX, int startY) {
        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++) {
                labyrinth->grid[x][y] = Cell();
            }
        }
  
        labyrinth->grid[startX][startY].setVisited(true);
  
        generateMazeRecursive(labyrinth, Point(startX, startY), sizeX, sizeY); // Start the generation process
    }

    void generateMaze(Labyrinth *labyrinth, int size) {
        generateMaze(labyrinth, size, size);
    }


    void generateMaze(Labyrinth *labyrinth, int sizeX, int sizeY) {
        int startX = (int) random(sizeX);
        int startY = (int) random(sizeY);
  
        generateMaze(labyrinth, sizeX, sizeY, startX, startY);
    }

    /*======================================================================
                              Generation methods
    ========================================================================*/

    // This method take in the grid and a position and return the the indexes of the free neighbours at this position
    NeighbourPoints getFreeNeighbours(Labyrinth *labyrinth, Point position, int w, int h) {
        NeighbourPoints freeNeighbours = NeighbourPoints();
  
        for (Point direction : directions) {
            Point neighbourPosition = Point::add(position, direction);
    
            if (isPointInsideGrid(neighbourPosition, w, h) && isCellFree(labyrinth, neighbourPosition)) {  // Make sure the neighbour is part of the grid and is free
                freeNeighbours.neighbours[freeNeighbours.count++] = neighbourPosition;
            }
        }
  
        return freeNeighbours;
    }

    // A cell is free if doesn't exist in the grid
    boolean isCellFree(Labyrinth *labyrinth, Point position) {
        return !labyrinth->grid[position.x][position.y].getVisited();
    }

    boolean isPointInsideGrid(Point point, int w, int h) {
        return point.x >= 0 && point.x <= w - 1 && point.y >= 0 && point.y <= h - 1;
    }

    void generateMazeRecursive(Labyrinth *labyrinth, Point position, int w, int h) {
        Point newCellPosition = Point(0, 0);
  
        for (int i = 0; i < 4; i++) { // Loop for times at max (Their cannot be more than 4 neighbours)
            NeighbourPoints freeNeighbours = getFreeNeighbours(labyrinth, position, w, h);
            if (freeNeighbours.count == 0) {
                return; // If you don't have any neighbour (stuck) return to your caller (the previous cell)
            }
  
            int index = (int) random(freeNeighbours.count);
    
            newCellPosition = freeNeighbours.neighbours[index];
    
            // Get the current cell and create the new one
            Cell currentCell = labyrinth->grid[position.x][position.y];
    
            // Place the new cell in the grid
            Cell newCell = labyrinth->grid[newCellPosition.x][newCellPosition.y];
            newCell.setVisited(true);
    
            // Connect both cells (remove the wall between them)
            currentCell.connect(position, newCellPosition);
            newCell.connect(newCellPosition, position);
    
            // Move on to the new cell
            generateMazeRecursive(labyrinth, newCellPosition, w, h);
        }
    }

    void openLabyrinth(Labyrinth *labyrinth, int w, int h) {
        labyrinth->grid[0][0].setWallUp(false);
        labyrinth->grid[w - 1][h - 1].setWallDown(false);
    }

    namespace {
        Point directions[4] = {POINT_UP, POINT_RIGHT, POINT_DOWN, POINT_LEFT};
    }
}