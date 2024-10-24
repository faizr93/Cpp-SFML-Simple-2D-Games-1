#include <stdio.h>
#include "game.h"
#include "game.cpp"

using namespace sf;
int main()
{
    // Init Game Engine
    Game game;

    // Game loop
    while (game.isRunning())
    {
        // Update
        game.update();

        // Render
        game.render();
    }

    // End of Application
    return 0;
}