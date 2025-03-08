#include "..\..\include\States\MainMenu.h"
#include <SFML/Graphics/Font.hpp>
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow * window, std::stack<State*> * states): State(window,states){

    if(!font.openFromFile("assets/fonts/arial.ttf")) {
        //handle
    }

    sf::Color idleColor = sf::Color::White;
    sf::Color activeColor = sf::Color::Red;
    float textSize = 30;

    buttons["Play"] = new Button((*window), "Play", font, textSize, idleColor, activeColor);
    buttons["Options"] = new Button((*window), "Options", font, textSize, idleColor, activeColor);
    buttons["Exit"] = new Button((*window), "Exit", font, textSize, idleColor, activeColor);

    buttons["Play"] -> addSpacing(textSize + textSize/2);
    buttons["Exit"] -> addSpacing((-1)* (textSize + textSize/2));

    buttons["Play"] -> changeToActiveButton();

}

MainMenu::~MainMenu(){
    for(auto it = buttons.begin(); it != buttons.end(); it++) {
        delete (*it).second;
    }
}

void MainMenu::processInput(const sf::Time& deltaTime){

    while (const std::optional event = window -> pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window -> close();
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            window->setKeyRepeatEnabled(false);
            if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
                moveDown();
            if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
                moveUp();
        }
    }

    if(buttons["Play"] -> isPressed())
        states->push(new GameState(window, states));
    
    else if(buttons["Exit"] -> isPressed())
        (*window).close();
}

void MainMenu::update(const sf::Time& deltaTime) {
    processInput(deltaTime);
}

void MainMenu::render(sf::RenderWindow &window){
    for(auto &it : buttons) {
        it.second -> render(window);
    }
}

void MainMenu::moveDown(){
    if(buttons["Play"] -> isActive()) {
        buttons["Play"] -> changeToIdleButton();
        buttons["Options"] -> changeToActiveButton();
    }
    else if(buttons["Options"] -> isActive()) {
        buttons["Options"] -> changeToIdleButton();
        buttons["Exit"] -> changeToActiveButton();
    }
    else if(buttons["Exit"] -> isActive()) {
        buttons["Exit"] -> changeToIdleButton();
        buttons["Play"] -> changeToActiveButton();
    }
}

void MainMenu::moveUp(){
    if(buttons["Play"] -> isActive()) {
        buttons["Play"] -> changeToIdleButton();
        buttons["Exit"] -> changeToActiveButton();
    }
    else if(buttons["Options"] -> isActive()) {
        buttons["Options"] -> changeToIdleButton();
        buttons["Play"] -> changeToActiveButton();
    }
    else if(buttons["Exit"] -> isActive()) {
        buttons["Exit"] -> changeToIdleButton();
        buttons["Options"] -> changeToActiveButton();
    }
}
