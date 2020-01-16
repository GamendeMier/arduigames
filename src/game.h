#pragma once

#include "LedControl.h"

#define DATA_PIN 11
#define CLOCK_PIN 13
#define CS_PIN 10

enum class GameError {
    Ok,
    Error
};

class Game {
public:
    Game();

    static bool button_pressed();

    void set_led(int x, int y, bool state);
	void clear_display();
	void set_char(int value);

    static float get_axis_x();
    static float get_axis_y();
    static void setup();

    virtual GameError update(float delta);
};
