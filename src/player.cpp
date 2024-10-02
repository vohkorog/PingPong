#include "player.hpp"


Player::Player(float posX, float posY, sf::Color color){
    this->color = color;
    this->posX = posX;
    this->posY = posY;
    this->initPlayer();
}

Player::Player(){

}

Player::~Player(){

}

void Player::initPlayer(){
    this->shape.setSize(sf::Vector2f(30, 200));
    this->shape.setPosition(this->posX, this->posY);
    this->shape.setFillColor(this->color);
}

sf::FloatRect Player::colision(){
    return this->shape.getGlobalBounds();
}


void Player::input(){
    if(this->color == sf::Color::Red){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(shape.getPosition().y > 0){
                this->shape.move(0, -0.1);
        }
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(shape.getPosition().y + shape.getGlobalBounds().height < 720){
                this->shape.move(0, 0.1);
            }
        }
    }
    if(this->color == sf::Color::Blue){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            if(shape.getPosition().y > 0){
                this->shape.move(0, -0.1);
        }
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if(shape.getPosition().y + shape.getGlobalBounds().height < 720){
                this->shape.move(0, 0.1);
            }
        }
    }
}

void Player::render(sf::RenderWindow *window){
    window->draw(this->shape);
}