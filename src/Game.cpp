#include "..\include\Game.h"

Game::Game(float widthScreen, float heightScreen) {

    // Init window
    window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(widthScreen, heightScreen)), "Arkanoid", sf::Style::Close | sf::Style::Titlebar);

    window->setFramerateLimit(120);
    window->setVerticalSyncEnabled(false);

    // Init states
    states.push(new MainMenu(window, &states));
}

Game::~Game(){
    delete window;

    while(!states.empty()) {
        delete states.top();
        states.pop();
    }
}


void Game::update(){

    // Time since last frame
    sf::Time deltaTime = sf::Time::Zero;
    deltaTime += clock.restart();

    

    if(!states.empty()) {
        states.top() -> update(deltaTime);
    }
    else
        window -> close();

    

}

void Game::render(){
    window -> clear();

    //menu.draw(window);

    if(!states.empty())
        states.top() -> render(*window);
    else
        window -> close();

    //draw player
    //window.draw(player);
    window -> display();
}

const bool Game::isRunning() const{
    return window -> isOpen();
}
