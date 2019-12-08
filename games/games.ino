#include "game.h"
#include "snake.h"
#include "arkanoid.h"

Game *game;

void setup() {
    game = new Arkanoid(12, 11, 10, 4);
}

void loop() {
    game->update(1.0f);
}
