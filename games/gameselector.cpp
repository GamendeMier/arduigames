#include "gameselector.h"

GameSelector::GameSelector(): Game() {
    shutdown(0,false);// turn off power saving, enables display
    setIntensity(0,8);// sets brightness (0~15 possible values)
    clearDisplay(0);// clear screen

    game = nullptr;
}


void GameSelector::update(float delta) {
    if (game != nullptr) {
        game->update(delta);
        return;
    }

    if (button_pressed) {
        setScreen(false);
        switch (int(current_selection)) {
        case 0:
            game = new Snake(4);
            break;
        case 1:
            game = new Arkanoid();
            break;
        }
    }

    setLed(0, (int)current_selection, 7, false);

    current_selection += get_axis_x()*delta*0.0001;

    setLed(0, (int)current_selection, 7, true);

}
