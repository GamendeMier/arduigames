#include "gameselector.h"

GameSelector::GameSelector(): Game() {
    game = nullptr;
}


GameError GameSelector::update(float delta) {
    if (game != nullptr) {
        game->update(delta);
        return;
    }

    if (Game::button_pressed()) {
        //setScreen(false); TODO: make a function to clear screen
        switch (int(current_selection)) {
        case 0:
            game = new Snake(4);
            set_led((int)current_selection, select_row, false);
            break;
        case 1:
            game = new Arkanoid();
            set_led((int)current_selection, select_row, false);
            break;
        }
    }

    set_led((int)current_selection, select_row, false);

    current_selection += get_axis_x()*delta*0.0001;

    set_led((int)current_selection, select_row, true);

    return GameError::Ok;
}
