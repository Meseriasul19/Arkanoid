#include "../../include/Entities/Collider.h"

Collider::Collider(sf::Sprite* body): body(body){}


sf::Vector2f Collider::getHalfSize(){
    return sf::Vector2f(body -> getGlobalBounds().size.x / 2, body->getGlobalBounds().size.y / 2);
}

void Collider::Move(float dx, float dy){
    body -> move(sf::Vector2f(dx,dy));
}


Collider::~Collider(){}

sf::Vector2f Collider::getDelta(Collider& otherBody){
    float dx = otherBody.body -> getPosition().x - body -> getPosition().x;
    float dy = otherBody.body -> getPosition().y - body -> getPosition().y;

    sf::Vector2f delta = sf::Vector2f(dx,dy);
    return delta;
}

sf::Vector2f Collider::getIntersect(Collider& otherBody){
    float dx = (otherBody.body -> getPosition().x) - (body -> getPosition().x);
    float dy = (otherBody.body -> getPosition().y) - (body -> getPosition().y);

    sf::Vector2f delta = sf::Vector2f(dx,dy);
    float intersectX = abs(delta.x) - (otherBody.getHalfSize().x + getHalfSize().x);
    float intersectY = abs(delta.y) - (otherBody.getHalfSize().y + getHalfSize().y);

    sf::Vector2f intersect = sf::Vector2f(intersectX, intersectY);
    return intersect;
}