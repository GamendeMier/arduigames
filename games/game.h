#pragma once

// Fix for auto completion
#ifdef ARDUINO
#include "LedControl.h"
#else
#include "../../libraries/LedControl/src/LedControl.h"
#endif

#define DATA_PIN 11
#define CLOCK_PIN 13
#define CS_PIN 10

class Game : public LedControl {
protected:
    Game();

    static bool button_pressed();

    void setScreen(bool is_on);

public:
    static float get_axis_x();
    static float get_axis_y();
    static void setup();

    virtual void update(float delta);
};
