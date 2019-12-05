#define BD_LEFT 0
#define BD_STOP 1
#define BD_RIGHT 2

class BlockDestroyer {
public:
    LedMatrix *matrix;

    float paddle_pos;

    FVec2 ball;
    FVec2 ball_velocity;

    int state;

    BlockDestroyer() {
        matrix = new LedMatrix(8, 8);

        paddle_pos = 4.5f;

        ball = {4.0f, 4.0f};
        ball_velocity = {0.0f, 1.0f};

        state = BD_LEFT;
    }



    int update(float delta) {
        // BALL
        matrix->unset_led((int)ball.x, (int)ball.y);

        ball.x += ball_velocity.x * delta;
        ball.y += ball_velocity.y * delta;
        
        if (ball.y > 8.0)
            return GAME_OVER;

        matrix->set_led((int)ball.x, (int)ball.y);

        // PADDLE
        // undraw ?
        matrix->unset_led(((int)paddle_pos)-1, 7);
        matrix->unset_led((int)paddle_pos, 7);
        matrix->unset_led(((int)paddle_pos)+1, 7);
        switch (state) {
            case BD_LEFT:
                paddle_pos -= delta * 2;
                break;
            case BD_RIGHT:
                paddle_pos += delta * 2;
                break;
        }

        if (paddle_pos < 0.0)
            state = BD_RIGHT;
        else if (paddle_pos > 8.0)
            state = BD_LEFT;

        // Draw paddle
        //matrix->clear_row(7);
        matrix->set_led(((int)paddle_pos)-1, 7);
        matrix->set_led((int)paddle_pos, 7);
        matrix->set_led(((int)paddle_pos)+1, 7);

        return GAME_OK;
    }
};
