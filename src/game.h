#pragma once

#include "LedControl.h"

#define DATA_PIN 11
#define CLOCK_PIN 13
#define CS_PIN 10

class Game {
protected:
    Game();

    static bool button_pressed();

    void set_led(int x, int y, bool state);

    static int random(int start, int end);

public:
    static float get_axis_x();
    static float get_axis_y();
    static void setup();

    virtual void update(float delta);
};
