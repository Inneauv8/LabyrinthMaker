#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point Point::add(Point p1, Point p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}