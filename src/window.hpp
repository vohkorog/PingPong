#pragma once 
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "ball.hpp"
#include <string>
class Window{
    private:
        Player *playerOne;
        Player *playerTwo;
        Ball *ball;
        sf::RenderWindow *window;
        sf::VideoMode videoMode;
        sf::Event event;
        int screen_width;
        int screen_height;
        std::string title;

        void initVar();
        void initWindow();
    public:
        Window(int screen_width, int screen_height, std::string title);
        virtual ~Window();
        void update();
        void render();
        void input();
        const bool running() const;
};