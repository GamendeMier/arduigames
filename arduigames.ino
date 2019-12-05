#include "ledmatrix.h"

#define SNAKE

#ifndef ARDUINO
// hier moeten libraries komen die niet voor arduino zijn
#endif

#define AXIS_X A0
#define AXIS_Y A1
#define BTN1 D2

#define GAME_OK 0
#define GAME_OVER 1

#ifdef SNAKE
#include "snake.h"
Snake *game = new Snake();
#endif

#ifdef BLOCK
#include "blockdestroyer.h"
BlockDestroyer *game = new BlockDestroyer();
#endif

void setup() {
#ifdef ARDUINO
    LedMatrix::setup();
#endif
}

int game_state;

void loop() {
    if (game_state != GAME_OVER) {
        game_state = game->update(0.0001f);
        game->matrix->draw_all();
    }
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
