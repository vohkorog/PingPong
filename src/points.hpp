#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>

class Points{
    private:
    std::string points;
    sf::Font font;

    public:
        sf::Text text;
        Points();
        Points(std::string points);
        void setText(std::string text);
        void render(sf::RenderWindow *window);
        void setPosition(int x, int y);
        void setPoints(int num);
};