#include "game.h"
#include "snake.h"

Snake *game;

int main() {
    Game::setup();
    game = new Snake(4);

    while (true)
        game->update(0.00001);

    return 0;
}
