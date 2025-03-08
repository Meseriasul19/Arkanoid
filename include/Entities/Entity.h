#pragma once
#include <SFML/Graphics.hpp>
//#include "Collider.h"

class Entity{
    protected:
        sf::Sprite entity;
        sf::Vector2i entitySize;
        sf::Vector2f entityPosition;

    public:
        Entity(sf::Texture& texture, sf::Vector2i indexPos, sf::Vector2i size):entity(texture){
            entitySize = size;
            entity.setTextureRect(sf::IntRect(indexPos, entitySize));
        }
        virtual ~Entity(){};
        
        virtual void render(sf::RenderWindow&) = 0;

        sf::Vector2f getPosition(){return entityPosition;};
        sf::Vector2i getSize(){return entitySize;};

};