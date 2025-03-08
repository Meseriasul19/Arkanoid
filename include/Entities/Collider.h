#pragma once
#include <SFML/Graphics.hpp>

class Collider{
    protected:
        sf::Sprite* body;
    public:
        Collider(sf::Sprite*);

        void Move(float, float);
        sf::Vector2f getHalfSize();
        ~Collider();

        sf::Vector2f getDelta(Collider&);
        sf::Vector2f getIntersect(Collider&);
};