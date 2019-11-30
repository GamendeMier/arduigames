#include "ledmatrix.h"

#include "snake.h"

#ifndef ARDUINO
// hier moeten libraries komen die niet voor arduino zijn
#endif


#define AXIS_X A0
#define AXIS_Y A1
#define BTN1 D2

Snake *game;

void setup() {
#ifdef ARDUINO
    LedMatrix::setup();
#endif
    game = new Snake();
}

void loop() {
#ifdef ARDUINO
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
