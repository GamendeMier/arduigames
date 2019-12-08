#pragma once

#include "LedControl.h"

class Game : protected LedControl {
protected:
    Game(int dataPin, int clkPin, int csPin);

    static float get_axis_x();
    static float get_axis_y();
    static bool button_pressed();

public:
    static void setup();

    virtual void update(float delta);
};
