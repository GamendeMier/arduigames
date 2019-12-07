#pragma once

#include "game.h"
#include "util.h"

class Snake : public Game {
private:
    Vec2<float> head;
    Vec2<int> *tail;

    int tail_len;

    Direction dir;

public:
    Snake(int dataPin, int clkPin, int csPin, int start_len);

    void update(float delta);
};
