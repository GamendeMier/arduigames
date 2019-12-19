#include "snake.h"

/*
void Snake::calc_direction(int old, bool turn) {
    if (turn == TURN_LEFT) {
        switch (old) {
        case UP:
            return LEFT;
        case LEFT:
            return DOWN;
        case DOWN:
            return RIGHT;
        case RIGHT:
            return UP;
        }
    } else {
        switch (old) {
        case UP:
            return RIGHT;
        case LEFT:
            return UP;
        case DOWN:
            return LEFT;
        case RIGHT:
            return DOWN;
        }
    }
    return 0;
}*/

Snake::Snake(int start_len): Game() {
    tail = (Vec2<int>*)malloc(sizeof(Vec2<int>)*8*8);

    tail_len = start_len;

    for (int i = 0; i < start_len; i++) {
        tail[i] = { start_len - i, 0 };
        set_led(start_len-i, 0, true);
    }
    head = { (float)start_len, 0.f };

    dir = Direction::Down;

    new_candy();
    set_led(candy.x, candy.y, true);
}

void Snake::update(float delta) {
    auto ax = Game::get_axis_x() - 512.f;
    auto ay = Game::get_axis_y() - 512.f;

    if (abs(ax) > abs(ay)) {
        // Left/RIght
        if (ax < 0) {
            dir = Direction::Left;
        } else {
            dir = Direction::Right;
        }
    } else {
        if (ay < 0) {
            dir = Direction::Down;
        } else {
            dir = Direction::Up;
        }
    }

    switch (dir) {
    case Direction::Up:
        head.y -= delta;
        break;
    case Direction::Left:
        head.x -= delta;
        break;
    case Direction::Down:
        head.y += delta;
        break;
    case Direction::Right:
        head.x += delta;
        break;
    }
    if (
        (int)head.x != tail[0].x ||
        (int)head.y != tail[0].y
   ) {
        if ((int)head.x == candy.x && (int)head.y == candy.y) {
            tail[tail_len++] = {0,0}; // can be anything
        } else {
            set_led(tail[tail_len-1].x, tail[tail_len-1].y, false);
        }

        for (int i = tail_len-1; i > 0; i--) {
            tail[i].x = tail[i-1].x;
            tail[i].y = tail[i-1].y;
        }

        if ((int)head.x == candy.x && (int)head.y == candy.y) {
            new_candy();
            set_led(candy.x, candy.y, true);
        }

        switch (dir) {
        case Direction::Up:
            tail[0].y -= 1;
            break;
        case Direction::Left:
            tail[0].x -= 1;
            break;
        case Direction::Down:
            tail[0].y += 1;
            break;
        case Direction::Right:
            tail[0].x += 1;
            break;
        }

        set_led(tail[0].x, tail[0].y, true);
    }
}

void Snake::new_candy() {
loop:
    candy = {Game::random(0,8), Game::random(0,8)};
    for (int i = 0; i < tail_len; i++) {
        if (tail[i].x == candy.x && tail[i].y == candy.y)
            goto loop;
    }
}
