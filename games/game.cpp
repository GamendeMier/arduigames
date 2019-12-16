#include "game.h"
#include "LedControl.h"

static void Game::setup() {
    pinMode(2, INPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}

Game::Game() : LedControl(DATA_PIN, CLOCK_PIN, CS_PIN, 1) {
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


void Game::setScreen(bool is_on) {
    for (int x = 0; x < 8; x++)
        for (int y = 0; x < 8; x++)
            setLed(0, x, y, is_on);
}
