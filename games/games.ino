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
