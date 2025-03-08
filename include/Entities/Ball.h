#pragma once
#include "Entity.h"

class Ball: public Entity{
    private:
        float movementSpeed = 100.f;
        sf::Vector2f direction;
        sf::Vector2f intersect;
        sf::Vector2f delta;

    public:
        Ball(sf::Texture&, sf::Vector2i, sf::Vector2i);
        ~Ball();

        void move(const sf::Time&);
        void render(sf::RenderWindow&);

        void setStartPosition(sf::RenderWindow&);
        void setStartDirection();

        void changeDirection(Entity&);

        bool isColliding(Entity&);
};