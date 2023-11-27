#ifndef NEIGHBOUR_POINTS_H
#define NEIGHBOUR_POINTS_H

#include "Point.h"
#include "Arduino.h"

struct NeighbourPoints {
  NeighbourPoints() {}

  Point neighbours[4] = {Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)};
  uint8_t count = 0;
};

#endif // NEIGHBOUR_POINTS_H