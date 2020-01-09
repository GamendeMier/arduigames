#include "arkanoid.h"

Arkanoid::Arkanoid(): Game() {
    paddle_pos = 4.5f;
    ball = {4.0f, 4.0f};
    ball_velocity = {0.0f, 1.0f};
    state = State::Left;
}

void Arkanoid::update(float delta) {
    set_led((int)ball.x, (int)ball.y, true);

    ball.x += ball_velocity.x * delta;
    ball.y += ball_velocity.y * delta;

    if (ball.y > 8.0)
        return;

    set_led((int)ball.x, (int)ball.y, true);

    set_led(((int)paddle_pos)-1, 7, false);
    set_led( (int)paddle_pos   , 7, false);
    set_led(((int)paddle_pos)+1, 7, false);

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

    set_led(((int)paddle_pos)-1, 7, true);
    set_led( (int)paddle_pos   , 7, true);
    set_led(((int)paddle_pos)+1, 7, true);
}

void Arkanoid::calculate_collision() {
}
