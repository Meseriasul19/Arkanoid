#pragma once
#include "State.h"
#include "GameState.h"
#include "../Button.h"
#include <map>

#define NR_OF_MENU_ITEMS 3

class MainMenu: public State {
    private:
        sf::Font font;
        std::map <std::string, Button *> buttons;

    public:
        MainMenu(sf::RenderWindow *, std::stack<State*> *);
        virtual ~MainMenu();

        void processInput(const sf::Time&);
        void update(const sf::Time&);
        void render(sf::RenderWindow &);

        void moveDown();
        void moveUp();
};