#pragma once

#include "game.h"
#include "snake.h"
#include "arkanoid.h"

class GameSelector : public Game {
private:
    int dataPin;
    int clkPin;
    int csPin;

    Game *game;

    float current_selection;

public:
    GameSelector(int dataPin, int clkPin, int csPin);

    void update(float delta);
};
