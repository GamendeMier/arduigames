#include "gameselector.h"

GameSelector::GameSelector(int dataPin, int clkPin, int csPin)
    : Game(dataPin, clkPin, csPin)
    , dataPin(dataPin)
    , clkPin(clkPin)
    , csPin(csPin)
{
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
            game = new Snake(dataPin, clkPin, csPin, 4);
            break;
        case 1:
            game = new Arkanoid(dataPin, clkPin, csPin);
            break;
        }
    }

    setLed(0, (int)current_selection, 7, false);

    current_selection += get_axis_x()*delta*0.0001;

    setLed(0, (int)current_selection, 7, true);

}
