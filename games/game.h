#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "LedControl.h"

class Game : protected LedControl {
protected:
    Game(int dataPin, int clkPin, int csPin);

public:
    virtual void update(float delta);
};

#endif // GAME_ENGINE_H
