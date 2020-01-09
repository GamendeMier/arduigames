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

    bool blocks[8*8];

    void calculate_collision();

    State state;

public:
    Arkanoid();

    void update(float delta);
};
