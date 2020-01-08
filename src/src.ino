#include "game.h"
#include "gameselector.h"
#include "snake.h"

GameSelector *game;

void setup() {
    Game::setup();
    Serial.begin(9600);

    game = new GameSelector();
}

void loop() {
    game->update(0.0005f);
}
