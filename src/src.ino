#include "game.h"
#include "snake.h"

Game *game;

void setup() {
    Game::setup();
    Serial.begin(9600);

    game = new Snake(4);
}

void loop() {
    game->update(0.0005f);
}
