
#define BD_LEFT 0
#define BD_STOP 1
#define BD_RIGHT 2

class BlockDestroyer {
public:
    LedMatrix *matrix;

    int paddle_pos;

    int state;

    BlockDestroyer() {
        matrix = new LedMatrix(8, 8);

        paddle_pos = 0;
    }



    void update(float delta) {
        
    }
}
