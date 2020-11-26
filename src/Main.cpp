#include <iostream>
#include <memory>
#include "Constants.h"
#include "Game.h"

int main(int argc, char *args[]) {
    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game->IsRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();

    return 0;
}
