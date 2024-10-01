#pragma once 
#include <SFML/Graphics.hpp>
#include <string>
class Player{
    private:
        void initPlayer();
        std::string texturePath;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Color color;
        sf::RectangleShape shape;
        float posX, posY;

    public:
        Player();
        Player(float posX, float posY, sf::Color color);
        ~Player();
        void update();
        void render(sf::RenderWindow *window);
        void input();
        sf::FloatRect colision();
};