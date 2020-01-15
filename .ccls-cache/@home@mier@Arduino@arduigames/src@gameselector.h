#pragma once

#include "game.h"
#include "snake.h"
#include "arkanoid.h"

class GameSelector : public Game {
private:
    Game *game;

    float current_selection;

    const int select_row = 4;

public:
    GameSelector();

    GameError update(float delta);
};
