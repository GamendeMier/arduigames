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

const byte IMAGES[][8] = {
{
  0B00000000,
  0B00000000,
  0B00000000,
  0B01000001,
  0B11111111,
  0B00000001,
  0B00000000,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B01000001,
  0B10000011,
  0B10000101,
  0B10001001,
  0B01110001,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B01000010,
  0B10000001,
  0B10010001,
  0B10010001,
  0B01101110,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B00001100,
  0B00010100,
  0B00100100,
  0B01000100,
  0B11111111,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B11110010,
  0B10010001,
  0B10010001,
  0B10010001,
  0B10001110,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B01111110,
  0B10010001,
  0B10010001,
  0B10010001,
  0B01001110,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B10000000,
  0B10000111,
  0B10001000,
  0B10010000,
  0B11100000,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B01101110,
  0B10010001,
  0B10010001,
  0B10010001,
  0B01101110,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B01110010,
  0B10001001,
  0B10001001,
  0B10001001,
  0B01111110,
  0B00000000
},{
  0B00000000,
  0B00000000,
  0B01111110,
  0B10000001,
  0B10000001,
  0B10000001,
  0B01111110,
  0B00000000
}};

void Game::set_char(int value) {
	if (value > 9 || value < 0)
		return;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			_lc.setLed(0, i, j, bitRead(IMAGES[value][i], 7 - j));
		}
	}
}
