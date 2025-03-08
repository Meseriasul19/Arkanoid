#pragma once
#include <SFML/Graphics.hpp>

class Button{
    private:
        sf::Text text;
        sf::Color idleColor;
        sf::Color activeColor;
        float x_pos;
        float y_pos;
        bool active;
        bool idle;

    public:
        Button(const sf::RenderWindow &, std::string, sf::Font &, float, sf::Color, sf::Color);
        void render(sf::RenderWindow&);
        void changeToIdleButton();
        void changeToActiveButton();
        void addSpacing(float);
        const bool isPressed();
        const bool isActive();
        const bool isIdle();
};