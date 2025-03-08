#include "..\..\include\Entities\Brick.h"

Brick::Brick(sf::Texture& texture, sf::Vector2i indexPos, sf::Vector2i size):Entity(texture, indexPos, size){}

Brick::~Brick(){}

void Brick::render(sf::RenderWindow& window){
    window.draw(entity);
}

void Brick::setPosition(sf::RenderWindow& window){
    int nrBricksX = 11;
    BrickPosition = sf::Vector2f((window.getSize().x - (nrBricksX * entitySize.x)) / 2 + (posX * entitySize.x)
    , posY * entitySize.y + entitySize.x);
    entity.setPosition(BrickPosition);
}

void Brick::setPosXY(int nrX, int nrY){
    posX = nrX;
    posY = nrY;
}
