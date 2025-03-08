#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>


class State {
    protected:
        std::stack<State*> * states;
        sf::RenderWindow * window;

    public:
        State(sf::RenderWindow * window, std::stack<State*> * states): window(window), states(states){};
        virtual ~State(){};
        //virtual void Init() = 0;
        virtual void processInput(const sf::Time&) = 0;
        virtual void update(const sf::Time& deltaTime) = 0;
        virtual void render(sf::RenderWindow&) = 0;
};
