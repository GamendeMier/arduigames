#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#define TURN_LEFT false
#define TURN_RIGHT true

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
    // Het hoofd van de slang is opgeslagen in een float
    // anders wordt alles 1 of 2 blokken
    FVec2 f_head;
    Vec2 *tail;
    int tail_len;

    LedMatrix *matrix;

    Snake() {
        direction = DOWN;
        tail_len = 4;

        matrix = new LedMatrix(8,8);

        tail = (Vec2*)malloc(sizeof(Vec2)*tail_len);
        for (int i = 0; i < tail_len; i++) {
            tail[i].x = (tail_len - i);
            tail[i].y = 0;
            matrix->set_led(tail_len-i, 0);
        }
        f_head.x = (int)tail[0].x;
        f_head.y = (int)tail[0].y;
    }

    int update(float delta) {
        switch (direction) {
        case UP:
            f_head.y -= delta;
            break;
        case LEFT:
            f_head.x -= delta;
            break;
        case DOWN:
            f_head.y += delta;
            break;
        case RIGHT:
            f_head.x += delta;
            break;
        }
        if (
            (int)f_head.x != tail[0].x ||
            (int)f_head.y != tail[0].y
       ) {

        
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
            matrix->set_led(tail[0].x, tail[0].y);
        }
        return GAME_OK;
    }
};
