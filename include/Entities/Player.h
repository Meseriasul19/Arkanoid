#pragma once
#include "Entity.h"
//#include "Collider.h"
#include <string>

class Player: public Entity{
    private: 

        bool isRightEdgeReached = false;
        bool isLeftEdgeReached = false;

        float movementSpeed = 200.f;

    public:
        Player(sf::Texture&, sf::Vector2i, sf::Vector2i);
        ~Player();

        void move(const sf::Time&);
        void render(sf::RenderWindow&);

        void setStartPosition(sf::RenderWindow&);
        sf::Vector2i getPlayerSize();

        void checkCollision(sf::RenderWindow&);

        //Collider getCollider(){return Collider((*entity), entitySize);}

};