#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

#include "States/GameState.h"
#include "States/MainMenu.h"

class Game{
    private:
        sf::RenderWindow * window = nullptr;
        std::stack<State*> states;
        //std::map<std::string, int> * key;
        sf::Clock clock;

    public:
        //Constructors / Destructor
        Game() = default;
        Game(float width, float height);
        ~Game();

        //Functions
        const bool isRunning() const;
        void update();
        void render();

};