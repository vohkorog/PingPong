#pragma once 
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "points.hpp"

class Ball{
    private:
        int pRed;
        int pBlue;
        Points *winner;
        Points *pointsBlue;
        Points *pointsRed;
        Points *palochka;
        Player *playerOne;
        Player playerTwo;
        sf::CircleShape ball;
        sf::Event event;
        sf::Vector2f pos;
        sf::Vector2f ballCenter;
        void initVar();
        float xVelocity;
        float yVelocity;

    public:
        Ball();
        Ball(float posX, float posY);
        ~Ball();
        void render(sf::RenderWindow *window);
        void update(Player *one, Player *two);
        void setPosition(float x, float y);
        float getRadius();
        sf::Vector2f getPosition();
};