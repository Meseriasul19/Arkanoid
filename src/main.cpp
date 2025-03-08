#include <SFML/Graphics.hpp>
#include "..\include\Game.h"
#include <iostream>

int main() {

    // Screen resolution
    // 64 * nr_of_bricks_per_line + margins = width
    // margins = 64 * 2
    unsigned int widthScreen = 832; 
    unsigned int heightScreen = 600;

    //chanhe to heap variables managemnet
    //MainMenu menu(widthScreen, heightScreen);
    Game game(widthScreen, heightScreen);

    while (game.isRunning())
    {
        // Update
        game.update();

        // Render
        game.render();
            
    }

    return 0;
}