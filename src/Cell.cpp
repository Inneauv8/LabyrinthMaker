#include "Cell.h"

void Cell::setWallRight(bool value) {
    if (value) {
        data |= 0b10000000;
    } else {
        data &= 0b01111111;
    }
}

bool Cell::getWallRight() {
    return data & 0b10000000;
}

void Cell::setWallLeft(bool value) {
    if (value) {
        data |= 0b01000000;
    } else {
        data &= 0b10111111;
    }
}

bool Cell::getWallLeft() {
    return data & 0b01000000;
}

void Cell::setWallUp(bool value) {
    if (value) {
        data |= 0b00100000;
    } else {
        data &= 0b11011111;
    }
}

bool Cell::getWallUp() {
    return data & 0b00100000;
}

void Cell::setWallDown(bool value) {
    if (value) {
        data |= 0b00010000;
    } else {
        data &= 0b11101111;
    }
}

bool Cell::getWallDown() {
    return data & 0b00010000;
}

void Cell::setVisited(bool value) {
    if (value) {
        data |= 0b00001000;
    } else {
        data &= 0b11110111;
    }
}

bool Cell::getVisited() {
    return data & 0b00001000;
}

void Cell::connect(Point cellPosition, Point connectedCellPosition) {
    int dx = connectedCellPosition.x - cellPosition.x;
    int dy = connectedCellPosition.y - cellPosition.y;
    
    if (dx < 0) {
        setWallLeft(false);
    } else if (dx > 0) {
        setWallRight(true);
    }
        
    if (dy < 0) {
        setWallUp(false);
    } else if (dy > 0) {
        setWallDown(true);
    }
}