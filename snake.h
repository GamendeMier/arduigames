#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#define TURN_LEFT false
#define TURN_RIGHT true

struct Vec2 {
public:
    int x;
    int y;
};

int calc_direction(int old, bool turn) {
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
    // dit is niet de bedoeling!!!!!!!!!!!
    return 0;
}

class Snake {
public:
    int direction;
    Vec2 *tail;
    int tail_len;
    LedMatrix *matrix;

    Snake() {
        direction = DOWN;
        tail_len = 4;

        matrix = new LedMatrix(8,8);

        tail = (Vec2*)malloc(sizeof(Vec2)*tail_len);
        for (int i = 0; i < tail_len; i++) {
            tail[i].x = tail_len - i;
            tail[i].y = 0;
            matrix->set_led(tail_len-i, 0);
        }
    }

    void update() {
        matrix->unset_led(tail[tail_len-1].x, tail[tail_len-1].y);

        for (int i = tail_len-1; i > 0; i--) {
            tail[i].x = tail[i-1].x;
            tail[i].y = tail[i-1].y;
        }

        switch (direction) {
        case UP:
            tail[0].y -= 1;
            break;
        case LEFT:
            tail[0].x -= 1;
            break;
        case DOWN:
            tail[0].y += 1;
            break;
        case RIGHT:
            tail[0].x += 1;
            break;
        }
        //if (matrix->get_led(tail[0].x, tail[0].y))
        //    printf("Game Ended\n");

        matrix->set_led(tail[0].x, tail[0].y);
    }
};
