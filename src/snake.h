#pragma once

#include "game.h"
#include "util.h"


class Snake : public Game {
private:
    const float dead_zone = 128.f;

    Direction dir;

    Vec2<float> head;
    Vec2<int> tail[64];

    int tail_len;

    Vec2<int> candy;

    void new_candy();


public:
    Snake(int start_len);

    GameError update(float delta);
};
