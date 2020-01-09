#include "game.h"
#include "gameselector.h"
#include "snake.h"

GameSelector *game;

void setup() {
    Game::setup();
    Serial.begin(9600);

    game = new GameSelector();
}

int new_time = millis();

void loop() {
    int old_time = new_time;
    new_time = millis();

    game->update(((float)new_time-(float)old_time)/1000);
}
