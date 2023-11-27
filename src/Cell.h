#ifndef CELL_H
#define CELL_H

#include "Point.h"
#include "Arduino.h"

struct Cell {
    uint8_t data = 0b11110000;

    void setWallRight(bool value);
    bool getWallRight();

    void setWallLeft(bool value);
    bool getWallLeft();

    void setWallUp(bool value);
    bool getWallUp();

    void setWallDown(bool value);
    bool getWallDown();

    void setVisited(bool value);
    bool getVisited();

    void connect(Point cellPosition, Point connectedCellPosition);
};

#endif // CELL_H