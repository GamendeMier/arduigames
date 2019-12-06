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

Snake::Snake(int dataPin, int clkPin, int csPin, int start_len): Game(dataPin, clkPin, csPin) {
    tail = (Vec2<int>*)malloc(sizeof(Vec2<int>)*start_len);
    for (int i = 0; i < start_len; i++)
        tail[i] = { start_len - i, 0 };
    head = { start_len, 0 };
}

void Snake::update(float delta) {
    switch (dir) {
    case Up:
        head.y -= delta;
        break;
    case Left:
        head.x -= delta;
        break;
    case Down:
        head.y += delta;
        break;
    case Right:
        head.x += delta;
        break;
    }
    if (
        (int)head.x != tail[0].x ||
        (int)head.y != tail[0].y
   ) {
        setLed(0, tail[tail_len-1].x, tail[tail_len-1].y, false);

        for (int i = tail_len-1; i > 0; i--) {
            tail[i].x = tail[i-1].x;
            tail[i].y = tail[i-1].y;
        }

        switch (dir) {
        case Up:
            tail[0].y -= 1;
            break;
        case Left:
            tail[0].x -= 1;
            break;
        case Down:
            tail[0].y += 1;
            break;
        case Right:
            tail[0].x += 1;
            break;
        }

        setLed(0, tail[0].x, tail[0].y, true);
    }
}
