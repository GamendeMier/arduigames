#pragma once

#include "game.h"
#include "util.h"

class Snake : public Game {
private:
    const float dead_zone = 128.f;

    Direction dir;

    Vec2<float> head;
    Vec2<int> tail[64];

    Vec2<int> candy;

    void new_candy();


public:
    Snake(int start_len);

    int tail_len;

    GameError update(float delta);
};
