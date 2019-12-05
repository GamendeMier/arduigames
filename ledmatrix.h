#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#ifndef ARDUINO
#include <cstdlib>
#include <cstdio>
#include <cstring>
#else
#include "LedControl.h"
LedControl lc=LedControl(11,13,10,1);
#endif

struct Vec2 {
public:
    int x;
    int y;
};

struct FVec2 {
    float x;
    float y;
};

class LedMatrix {
public:
    bool *leds;
    int width;
    int height;

    LedMatrix(int _width, int _height) {
        width = _width;
        height = _height;

        leds = (bool*)malloc(sizeof(bool)*width*height);
        memset(leds, false, sizeof(bool)*width*height);
    }

    static void setup() {
#ifdef ARDUINO
        lc.shutdown(0,false);// turn off power saving, enables display
        lc.setIntensity(0,8);// sets brightness (0~15 possible values)
        lc.clearDisplay(0);// clear screen
#endif
    }

    bool is_valid(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return false;
        return true;
    }

    void set_led(int x, int y) {
        if (!is_valid(x,y)) return;
        leds[y*width+x] = true;
    }

    void unset_led(int x, int y) {
        if (!is_valid(x,y)) return;
        leds[y*width+x] = false;
    }

    bool get_led(int x, int y) {
        if (!is_valid(x,y)) return true;
        return leds[y*width+x];
    }

    void clear_row(int y) {
        memset(leds+y*width, false, sizeof(bool)*width);
    }

    void draw_all() {
#ifdef ARDUINO
        for (int row = 0; row < height; row++) {
            //digitalWrite(row+10, HIGH);

            for (int col = 0; col < width; col++) {
                lc.setLed(0,col,row,get_led(col,row));
                delay(25);
                //digitalWrite(col+2, get_led(col, row) ? LOW : HIGH);
            }

            //delayMicroseconds(1000);
            //digitalWrite(row+10, LOW);
        }
#else
        printf("\x1b[8A");
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++)
                fputs(get_led(col,row) ? " # " : " . ", stdout);
            printf("\n");
        }
#endif
    }
};


#endif // LEDMATRIX_H
