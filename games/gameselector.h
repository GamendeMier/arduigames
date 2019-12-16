#pragma once

#include "game.h"
#include "snake.h"
#include "arkanoid.h"

class GameSelector : public Game {
private:
    Game *game;

    float current_selection;

public:
    GameSelector();

    void update(float delta);
};
