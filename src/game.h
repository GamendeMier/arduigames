#pragma once

// Fix for auto completion
#ifdef ARDUINO

#include "LedControl.h"

#define DATA_PIN 11
#define CLOCK_PIN 13
#define CS_PIN 10

#else

#include <curses.h>

#endif

class Game {
protected:
    Game();

    static bool button_pressed();

    void set_led(int x, int y, bool state);

public:
    static float get_axis_x();
    static float get_axis_y();
    static void setup();

    virtual void update(float delta);
};
