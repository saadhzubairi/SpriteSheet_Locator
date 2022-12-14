#include <SDL.h>
#include <string>
#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {

    game = new Game();

    const int FPS = 1000;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game->init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, false);

    while (game->running() == true) {

        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        game->deleteDeadStuff();
        game->checkCollisions();
        game->respawnEnemies();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}