#include "game.h"
#include "snake.h"

Snake *game;

void setup() {
    Game::setup();

    game = new Snake(4);
}

void loop() {
    game->update(0.0005f);
}
