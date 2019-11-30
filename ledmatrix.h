#ifndef ARDUINO
#include <cstdlib>
#include <cstdio>
#include <cstring>
#endif

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


    void draw_all() {
#ifdef ARDUINO
        // Verander dit voor het nieuwe ding
        for (int row = 0; row < height; row++) {
            digitalWrite(row+10, HIGH);

            for (int col = 0; col < width; col++)
                digitalWrite(col+2, get_led(col, row) ? LOW : HIGH);

            delayMicroseconds(1000);
            digitalWrite(row+10, LOW);
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


