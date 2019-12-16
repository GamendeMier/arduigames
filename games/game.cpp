#include "game.h"
#include "LedControl.h"

LedControl _lc(DATA_PIN, CLOCK_PIN, CS_PIN, 1);

static void Game::setup() {
    _lc.shutdown(0,false);
    _lc.setIntensity(0,8);
    _lc.clearDisplay(0);

    pinMode(2, INPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}

Game::Game() {
}

// Check if this is correct
static float Game::get_axis_x() {
    return analogRead(A0);
    //return ((float)(analogRead(A0)-512))/512.f;
}

static float Game::get_axis_y() {
    return analogRead(A1);
    //return ((float)(analogRead(A1)-512))/512.f;
}

static bool Game::button_pressed() {
    return digitalRead(2) == HIGH;
}

void Game::set_led(int x, int y, bool state) {
    _lc.setLed(0, x, y, state);
}
