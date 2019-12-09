#include "arkanoid.h"

Arkanoid::Arkanoid(int dataPin, int clkPin, int csPin): Game(dataPin, clkPin, csPin) {
    paddle_pos = 4.5f;
    ball = {4.0f, 4.0f};
    ball_velocity = {0.0f, 1.0f};
    state = State::Left;
}

void Arkanoid::update(float delta) {
    setLed(0, (int)ball.x, (int)ball.y, true);

    ball.x += ball_velocity.x * delta;
    ball.y += ball_velocity.y * delta;

    if (ball.y > 8.0)
        return;

    setLed(0, (int)ball.x, (int)ball.y, true);

    setLed(0, ((int)paddle_pos)-1, 7, false);
    setLed(0,  (int)paddle_pos   , 7, false);
    setLed(0, ((int)paddle_pos)+1, 7, false);

    switch (state) {
        case State::Left:
            paddle_pos -= delta * 2;
            break;
        case State::Right:
            paddle_pos += delta * 2;
            break;
    }

    if (paddle_pos < 0.0)
        state = State::Right;
    else if (paddle_pos > 8.0)
        state = State::Left;

    setLed(0, ((int)paddle_pos)-1, 7, true);
    setLed(0,  (int)paddle_pos   , 7, true);
    setLed(0, ((int)paddle_pos)+1, 7, true);
}
