#pragma once

#include "game.h"
#include "util.h"

enum class State {
    Left,
    Right,
    Stop
};

class Arkanoid : public Game {
private:
    float paddle_pos;

    Vec2<float> ball;
    Vec2<float> ball_velocity;

    State state;

public:
    Arkanoid(int dataPin, int clkPin, int csPin, int start_len);

    void update(float delta);
};
