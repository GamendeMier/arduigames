#include "game.h"

Game::Game() {}

LedControl _lc(DATA_PIN, CLOCK_PIN, CS_PIN, 1);

void Game::setup() {
    _lc.shutdown(0,false);
    _lc.setIntensity(0,8);
    _lc.clearDisplay(0);

    pinMode(2, INPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}


float Game::get_axis_x() {
    return analogRead(A0)-512.f;
}

float Game::get_axis_y() {
    return analogRead(A1)-512.f;
}

bool Game::button_pressed() {
    return digitalRead(2) == HIGH;
}

void Game::set_led(int x, int y, bool state) {
    _lc.setLed(0, x, y, state);
}

void Game::clear_display() {
	_lc.clearDisplay(0);
}

void Game::set_char(int pos, char value) {
	_lc.setChar(0, pos, value, false);
}
