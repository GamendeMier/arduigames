#include "game.h"
#include "snake.h"
#include "arkanoid.h"

Game *game;

void setup() {
    Game::setup();
    game = new Snake(5);

}

void loop() {
    game->update(0.0005f);
}
