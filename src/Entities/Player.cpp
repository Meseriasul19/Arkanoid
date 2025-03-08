#include "..\..\include\Entities\Player.h"

Player::Player(sf::Texture& texture, sf::Vector2i indexPos, sf::Vector2i size):Entity(texture, indexPos, size){}

void Player::move(const sf::Time& dt) {

    if(!isLeftEdgeReached) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            entity.move({-1.f * movementSpeed * dt.asSeconds(), 0.f});
            entityPosition = entity.getPosition();
        }
    }

    if(!isRightEdgeReached) {     
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            entity.move({1.f * movementSpeed * dt.asSeconds(), 0.f});
            entityPosition = entity.getPosition();
        }
    }
}

void Player::render(sf::RenderWindow& window) {
    window.draw(entity);
}

Player::~Player(){}

void Player::setStartPosition(sf::RenderWindow & window){
    
    entityPosition = sf::Vector2f(window.getSize().x  / 2 - (entitySize.x / 2), window.getSize().y  - entitySize.y);
    entity.setPosition(entityPosition);
    
}

sf::Vector2i Player::getPlayerSize(){
    return entitySize;
}

void Player::checkCollision(sf::RenderWindow& window){

    if(entityPosition.x <= 0.f) 
        isLeftEdgeReached = true;
    else 
        isLeftEdgeReached = false;

    if(entityPosition.x >= (window.getSize().x - entitySize.x)) 
        isRightEdgeReached = true;
    else 
        isRightEdgeReached = false;
    
}