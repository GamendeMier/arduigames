#include "ledmatrix.h"

#include "snake.h"

#ifndef ARDUINO
#include <unistd.h>
#endif


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

void loop() {
#ifdef ARDUINO
    if (analogRead(BUT2) != 0) {
        game->direction = calc_direction(game->direction, TURN_LEFT);
    } else if (analogRead(BUT3) != 0) {
        game->direction = calc_direction(game->direction, TURN_RIGHT);
    }
#else
    //usleep(1000000);
#endif
    game->update(0.0001f);
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
