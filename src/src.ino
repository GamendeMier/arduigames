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
        }

    } else {
		// dead TODO: fix this shit
		switch (game->tail_len) {
			case 0:
				game->set_char(0, '0');
				break;
			case 1:
				game->set_char(0, '1');
				break;
			case 2:
				game->set_char(0, '2');
				break;
			case 3:
				game->set_char(0, '3');
				break;
			case 4:
				game->set_char(0, '4');
				break;
			case 5:
				game->set_char(0, '5');
				break;
			case 6:
				game->set_char(0, '6');
				break;
			case 7:
				game->set_char(0, '7');
				break;
			case 8:
				game->set_char(0, '8');
				break;
			case 9:
				game->set_char(0, '9');
				break;

		}

    }
}
