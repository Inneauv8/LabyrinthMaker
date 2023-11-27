#include "Vertex.h"

bool Vertex::isRight() {
    return data & 0b10000000;
}

void Vertex::setRight(bool value) {
    if (value) {
        data |= 0b10000000;
    } else {
        data &= 0b01111111;
    }
}

bool Vertex::isLeft() {
    return data & 0b01000000;
}

void Vertex::setLeft(bool value) {
    if (value) {
        data |= 0b01000000;
    } else {
        data &= 0b10111111;
    }
}

bool Vertex::isUp() {
    return data & 0b00100000;
}

void Vertex::setUp(bool value) {
    if (value) {
        data |= 0b00100000;
    } else {
        data &= 0b11011111;
    }
}

bool Vertex::isDown() {
    return data & 0b00010000;
}

void Vertex::setDown(bool value) {
    if (value) {
        data |= 0b00010000;
    } else {
        data &= 0b11101111;
    }
}
    
int Vertex::getConnexionCount() {
    return (isUp() ? 1 : 0) + (isDown() ? 1 : 0) + (isRight() ? 1 : 0) + (isLeft() ? 1 : 0);
}
  
boolean Vertex::hasConnexions() {
    return bool(data);
}