#include "game.h"
#include "LedControl.h"

static void Game::setup() {
    pinMode(2, INPUT);

    pinMode(13, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
}

Game::Game(int dataPin, int clkPin, int csPin) : LedControl(dataPin, clkPin, csPin) {

}

// Check if this is correct
static float Game::get_axis_x() {
    return ((float)(analogRead(A0)-512))/512.f;
}

static float Game::get_axis_y() {
    return ((float)(analogRead(A1)-512))/512.f;
}

static bool Game::button_pressed() {

}
