#include "..\..\include\States\GameState.h"

GameState::GameState(sf::RenderWindow * window,  std::stack<State*> * states): 
State(window, states){

    loadTexture();
    initEntities();
    setStart();
    
}

GameState::~GameState(){
    delete player;
    delete ball;

}

void GameState::initEntities(){
    // TEXTURE GRID AND SIZE
    int nrXvertex = 35;
    int nrYvertex = 17;
    sf::Vector2u vertexSize(texture.getSize().x / nrXvertex, texture.getSize().y / nrYvertex);

    // ENTITIES TEXTURE INDEX POSITION AND SIZE
    // player
    sf::Vector2i playerIndexPos(vertexSize.x * 19, vertexSize.y * 10);
    sf::Vector2i playerSize(vertexSize.x * 16, vertexSize.y * 3);
    // ball
    sf::Vector2i ballIndexPos(vertexSize.x * 0, vertexSize.y * 10);
    sf::Vector2i ballSize(vertexSize.x * 3, vertexSize.y * 3);
    // brick
    sf::Vector2i brickIndexPos(vertexSize.x * 0, vertexSize.y * 0);
    sf::Vector2i brickSize(vertexSize.x * 8, vertexSize.y * 4);

    // BRICKS GRID
    int nrXBricks = 11;
    int nrYBricks = 5;

    // INIT ENTITIES
    player = new Player(texture, playerIndexPos, playerSize);
    ball   = new Ball(texture, ballIndexPos, ballSize);
    for(int y = 0; y < nrYBricks; y++){
        for(int x = 0; x < nrXBricks; x++){
            Brick brick(texture, brickIndexPos, brickSize);
            brick.setPosXY(x, y);
            bricks.emplace_back(brick);
        }
    }
}

void GameState::setStart(){
    player -> setStartPosition(*window);
    ball   -> setStartPosition(*window);
    ball   -> setStartDirection();
    for(int i = 0; i < bricks.size(); i++)
        bricks[i].setPosition(*window);
}

void GameState::update(const sf::Time& deltaTime){

    while (const std::optional event = window -> pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window -> close();
        else if(!gameStarted)
        {
            if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
                    gameStarted = true;
        }
    }

    processInput(deltaTime);
}

void GameState::processInput(const sf::Time& dt){
    if(gameStarted){

        player -> move(dt);
        ball -> move(dt);

        player -> checkCollision(*window);

        //if(ball -> isColliding(*player))
        //ball -> changeDirection(*player);
        
        for(auto it = bricks.begin(); it < bricks.end(); it++){
            if(ball -> isColliding(*it)){
                ball -> changeDirection(bricks[3]);
                bricks.erase(it);
                return;
            }
        }
    }
}

void GameState::render(sf::RenderWindow& window){
    player -> render(window);
    ball -> render(window);
    for(int i = 0; i < bricks.size(); i++)
        bricks[i].render(window);
}
void GameState::loadTexture(){
    if(!texture.loadFromFile("assets/textures/Blocks.png")) {
        // handle
    }
}





