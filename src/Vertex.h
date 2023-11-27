#ifndef VERTEX_H
#define VERTEX_H

#include "Arduino.h"

struct Vertex {
    uint8_t data = 0;

    bool isRight();
    void setRight(bool value);

    bool isLeft();
    void setLeft(bool value);

    bool isUp();
    void setUp(bool value);

    bool isDown();
    void setDown(bool value);
    
    int getConnexionCount();
  
    boolean hasConnexions();
};

#endif // VERTEX_H