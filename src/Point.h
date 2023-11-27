#ifndef POINT_H
#define POINT_H

struct Point {
    int x = 0;
    int y = 0;

    Point(int x, int y);

    static Point add(Point p1, Point p2);
};

static const Point POINT_UP = Point(0, -1);
static const Point POINT_DOWN = Point(0, 1);
static const Point POINT_RIGHT = Point(1, 0);
static const Point POINT_LEFT = Point(-1, 0);

#endif // POINT_H