#pragma once 
#include "State.h"
#include "../Entities/Player.h"
#include "../Entities/Ball.h"
#include "../Entities/Brick.h"

class GameState: public State{
    private:
        sf::Texture texture;

        Player * player;
        Ball * ball;
        std::vector<Brick> bricks;

        bool gameStarted = false;
    public:
        GameState(sf::RenderWindow *, std::stack<State*> *);
        virtual ~GameState();
        void processInput(const sf::Time&);
        void update(const sf::Time&);
        void render(sf::RenderWindow&);

        void loadTexture();
        void initEntities();
        void setStart();

};