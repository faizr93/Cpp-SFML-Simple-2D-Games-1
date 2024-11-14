#include <stdio.h>
#include "game.h"
#include "game.cpp"

// using namespace sf;
int main()
{
    //Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    // Init Game Engine
    Game game;

    // Game loop
    while (game.running() && !game.getEndGame())
    {
        // Update
        game.update();

        // Render
        game.render();
    }

    // End of Application
    return 0;
    
}