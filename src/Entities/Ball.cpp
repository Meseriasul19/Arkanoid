#include "..\..\include\Entities\Ball.h"

Ball::Ball(sf::Texture& texture, sf::Vector2i indexPos, sf::Vector2i size): Entity(texture, indexPos, size){}

void Ball::move(const sf::Time& dt){
    entity.move(sf::Vector2f(direction.x * dt.asSeconds(), direction.y * dt.asSeconds()));
    entityPosition = entity.getPosition();
}

void Ball::render(sf::RenderWindow& window){
    window.draw(entity);
}


void Ball::setStartPosition(sf::RenderWindow& window){
    entityPosition = sf::Vector2f(window.getSize().x  / 2 - (entitySize.x / 2), window.getSize().y  - (2 * entitySize.y));
    entity.setPosition(entityPosition);
}

Ball::~Ball(){}

void Ball::changeDirection(Entity& otherBody){

    if(abs(intersect.x) > abs(intersect.y)) {
        if(delta.x > 0.0f)
            direction = sf::Vector2f(intersect.x , 0.0f);

        else 
            direction = sf::Vector2f(-intersect.x, 0.0f);
    }

    else {
        if(delta.y > 0.0f) 
            direction = sf::Vector2f(0.0f, intersect.y);

        else 
            direction = sf::Vector2f(0.0f, -intersect.y);
    }

}

void Ball::setStartDirection(){
    direction = sf::Vector2f(0.f, -1.f * 100.0f);
}

bool Ball::isColliding(Entity& other){
    delta = sf::Vector2f(other.getPosition().x - entityPosition.x,other.getPosition().y - entityPosition.y);

    float intersectX = abs(delta.x) - ((other.getSize().x / 2) + (entitySize.x / 2));
    float intersectY = abs(delta.y) - ((other.getSize().y / 2) + (entitySize.y / 2));
    intersect = sf::Vector2f(intersectX, intersectY);

    if(intersect.x < 0.0f && intersect.y < 0.0f)
        return true;
    else return false;
}
