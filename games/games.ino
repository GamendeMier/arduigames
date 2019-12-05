#include "game.h"
#include "snake.h"

Game *game;

void setup() {
    game = new Snake(12, 11, 10, 4);
}

void loop() {
    game->update(1.0f);
}
