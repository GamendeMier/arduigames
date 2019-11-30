#ifndef ARDUINO
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#endif

struct Vec2 {
public:
    int x;
    int y;
};

class LedMatrix {
public:
    bool *leds;
    int width;
    int height;

    LedMatrix(int _width, int _height) {
        width = _width;
        height = _height;

        leds = (bool*)malloc(sizeof(bool)*width*height);
        memset(leds, false, sizeof(bool)*width*height);
    }

    bool is_valid(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return false;
        return true;
    }

    void set_led(int x, int y) {
        if (!is_valid(x,y)) return;
        leds[y*width+x] = true;
    }

    void unset_led(int x, int y) {
        if (!is_valid(x,y)) return;
        leds[y*width+x] = false;
    }

    bool get_led(int x, int y) {
        if (!is_valid(x,y)) return true;
        return leds[y*width+x];
    }


    void draw_all() {
#ifdef ARDUINO
        // Verander dit voor het nieuwe ding
        for (int row = 0; row < height; row++) {
            digitalWrite(row+10, HIGH);

            for (int col = 0; col < width; col++)
                digitalWrite(col+2, get_led(col, row) ? LOW : HIGH);

            delayMicroseconds(1000);
            digitalWrite(row+10, LOW);
        }
#else
        printf("\x1b[8A");
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++)
                fputs(get_led(col,row) ? " # " : " . ", stdout);
            printf("\n");
        }
#endif
    }
};


// Maak hier een enum van?
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

#define BUT1 1
#define BUT2 18
#define BUT3 19

Snake *game;

void setup() {
#ifdef ARDUINO
    // Pin 2 tot en met 17 zijn output
    for (int i = 2; i <= 17; i++)
        pinMode(i,OUTPUT);

    pinMode(BUT1,INPUT);
    pinMode(BUT2,INPUT);
    pinMode(BUT3,INPUT);
#endif
    game = new Snake();
}

// Delay in milliseconden
#define DELAY 1000

void loop() {
#ifdef ARDUINO
    delay()
    if (analogRead(BUT2) != 0) {
        game->direction = calc_direction(game->direction, TURN_LEFT);
    } else if (analogRead(BUT3) != 0) {
        game->direction = calc_direction(game->direction, TURN_RIGHT);
    }
#else
    // deze functie gebruikt microseconden
    usleep(DELAY * 1000);
#endif
    game->update();
    game->matrix->draw_all();
}


#ifndef ARDUINO
int main() {
    setup();
    // Clear Screen
    printf("\x1b[2J");

    while (true)
        loop();

    return 0;
}
#endif
