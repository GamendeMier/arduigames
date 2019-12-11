/*
#include "game.h"
#include "gameselector.h"

GameSelector *game_selector;

void setup() {
    Game::setup();
    game_selector = new GameSelector(13, 11, 10);
}

void loop() {
    game_selector->update(1.0f);
}
*/

#include "game.h"
#include "snake.h"

Game *game;

void setup() {
    Game::setup();
    game = new Snake(13, 11, 10, 1);
}

void loop() {
    game->update(0.0000001f);
}
