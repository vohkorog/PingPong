#include "points.hpp"


Points::Points(){

}

Points::Points(std::string points){
    this->font.loadFromFile("../fonts/SwftV01.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(70);
    this->text.setFillColor(sf::Color::White);
    this->points = points;
    this->text.setString(points);
}

void Points::setText(std::string text){
    this->text.setString(text);
}

void Points::setPoints(int num){
    std::ostringstream points;
    points << num;
    this->text.setString(points.str());
}

void Points::render(sf::RenderWindow *window){
    window->draw(this->text);
}

void Points::setPosition(int x, int y){
    this->text.setPosition(x, y);
}