#include "game.h"
#include "snake.h"

Snake *game;

void setup() {
    Game::setup();
    Serial.begin(9600);

    game = new Snake(4);
}

int new_time = millis();

bool is_dead = false;

void loop() {
    if (!is_dead) {
        int old_time = new_time;
        new_time = millis();

        auto error = game->update(((float)new_time-(float)old_time)/1000.f);

        if (error == GameError::Error) {
            is_dead = true;
			game->clear_display();
			game->set_char(game->tail_len - 4);
        }
    }
}
