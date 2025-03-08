#include "..\include\Button.h"


Button::Button(const sf::RenderWindow & window, std::string string, sf::Font & font, float textSize, sf::Color iColor, sf::Color aColor): idleColor(iColor), activeColor(aColor), text(font, string, textSize){

    //Color & Size
    text.setFillColor(idleColor);


    //Center position
    x_pos = window.getSize().x / 2.f;
    y_pos = window.getSize().y / 2.f;

    x_pos -= text.getGlobalBounds().size.x / 2.f;
    y_pos -= text.getGlobalBounds().size.y / 2.f;

    text.setPosition(sf::Vector2f(x_pos, y_pos));

}

void Button::render(sf::RenderWindow& window){
    window.draw(text);
}

void Button::changeToIdleButton(){
    text.setFillColor(idleColor);
    idle = true;
    active = false;
}

void Button::changeToActiveButton(){
    text.setFillColor(activeColor);
    active = true;
    idle = false;
}

void Button::addSpacing(float spacing) {
    text.setPosition(sf::Vector2f(x_pos, y_pos - spacing));
}

const bool Button::isPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && active == true)
        return true;
    else
        return false;
}

const bool Button::isActive(){
    return active;
}

const bool Button::isIdle(){
    return idle;
}


