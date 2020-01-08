#include "gameselector.h"

GameSelector::GameSelector(): Game() {
    game = nullptr;
}


void GameSelector::update(float delta) {
    if (game != nullptr) {
        game->update(delta);
        return;
    }

    if (button_pressed) {
        //setScreen(false); TODO: make a function to clear screen
        switch (int(current_selection)) {
        case 0:
            game = new Snake(4);
            break;
        case 1:
            game = new Arkanoid();
            break;
        }
    }

    set_led((int)current_selection, 7, false);

    current_selection += get_axis_x()*delta*0.0001;

    set_led((int)current_selection, 7, true);

}
