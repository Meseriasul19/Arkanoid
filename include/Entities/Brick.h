#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Brick: public Entity{
    private:
        int posX, posY;
        sf::Vector2f BrickPosition;

    public:
        Brick(sf::Texture&, sf::Vector2i, sf::Vector2i);
        ~Brick();

        virtual void render(sf::RenderWindow&);

        void setPosition(sf::RenderWindow&);
        void setPosXY(int, int);

};

