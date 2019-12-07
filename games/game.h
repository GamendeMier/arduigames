#pragma once

#include "LedControl.h"

class Game : protected LedControl {
protected:
    Game(int dataPin, int clkPin, int csPin);

public:
    virtual void update(float delta);
};
