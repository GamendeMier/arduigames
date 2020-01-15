#include "snake.h"

Snake::Snake(int start_len): Game() {
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

GameError Snake::update(float delta) {
    auto ax = Game::get_axis_x();
    auto ay = Game::get_axis_y();

    if (abs(ax) > abs(ay)) {
        // Left/RIght
        if (ax < - dead_zone) {
            dir = Direction::Left;
        } else if (ax > dead_zone){
            dir = Direction::Right;
        }
    } else {
        if (ay < - dead_zone) {
            dir = Direction::Down;
        } else if (ay > dead_zone){
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
		if (head.x > 8.0f || head.x < -1.0f || head.y > 8.0f || head.y < -1.0f)
			return GameError::Error;

        if ((int)head.x == candy.x && (int)head.y == candy.y) {
            tail[tail_len++] = {0,0}; // can be anything
        } else {
            set_led(tail[tail_len-1].x, tail[tail_len-1].y, false);
        }

        for (int i = tail_len-1; i > 0; i--) {
            /*
            for (int j = tail_len-1; j > 0; j--)
                if (i != j && tail[i].x == tail[j].x && tail[i].y == tail[j].y)
                    return GameError::Error;
            */
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

		head.x = (float)(int)head.x + 0.5f;
		head.y = (float)(int)head.y + 0.5f;

		for (int i = 1; i < tail_len; i++) {
			if (tail[i].x == tail[0].x && tail[i].y == tail[0].y) {
				return GameError::Error;
			}
		}

        set_led(tail[0].x, tail[0].y, true);
    }

    return GameError::Ok;
}

void Snake::new_candy() {
loop:
    candy = {random(0,8), random(0,8)};
    for (int i = 0; i < tail_len; i++) {
        if (tail[i].x == candy.x && tail[i].y == candy.y)
            goto loop;
    }
}
