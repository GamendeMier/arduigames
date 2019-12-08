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

}
