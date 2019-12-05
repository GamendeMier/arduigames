#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"
#include "util.h"

enum Direction {
    Up, Down, Left, Right
};

class Snake : public Game {
private:
    Vec2<float> head;
    Vec2<int> *tail;

    int tail_len;

    Direction dir;

public:
    Snake(int dataPin, int clkPin, int csPin, int start_len);

    void update(float delta);
    void draw();
};

#endif // SNAKE_H
