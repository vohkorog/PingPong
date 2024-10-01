#include "ball.hpp"
#include <iostream>
Ball::Ball(){

}

Ball::Ball(float posX, float posY)
{
    this->pos.x = posX;
    this->pos.y = posY;
    this->initVar();
}

void Ball::initVar()
{
    this->pRed =0;
    this->pBlue = 0;
    this->winner = new Points("");
    this->winner->setPosition(610, 300);
    this->pointsBlue = new Points("0");
    this->pointsBlue->setPosition(550,100);
    this->pointsRed = new Points("0");
    this->pointsRed->setPosition(650, 100);
    this->palochka = new Points("-");
    this->palochka->setPosition(597, 110);
    this->ball.setPosition(this->pos.x, this->pos.y);
    this->ball.setRadius(30);
    this->ball.setFillColor(sf::Color::Green);
    this->ballCenter = sf::Vector2f(this->ball.getPosition().x + this->ball.getRadius(), this->ball.getPosition().y + this->ball.getRadius());
    this->xVelocity = 0.1;
    this->yVelocity = 0.1;
}

Ball::~Ball(){

}

void Ball::render(sf::RenderWindow *window)
{
    this->pointsBlue->render(window);
    this->pointsRed->render(window);
    this->palochka->render(window);
    window->draw(this->ball);

    if(this->pBlue == 11){
        this->winner->setText("blue win");
        this->winner->render(window);
    }
    if(this->pRed == 11){
        this->winner->setText("red win");
        this->winner->render(window);
    }
}

void Ball::update(Player *one, Player *two)
{
    
    this->pos = this->ball.getPosition();
        
    if(this->pos.y < 0 || this->pos.y > 660) this->yVelocity *= -1;

    if(this->ball.getGlobalBounds().intersects(one->colision())){
        this->xVelocity *= -1;
    } 

    if(this->ball.getGlobalBounds().intersects(two->colision())){
        this->xVelocity *= -1;
    } 

    this->pos.x += this->xVelocity;
    this->pos.y += this->yVelocity;

    this->ball.setPosition(this->pos);

    if(this->ball.getPosition().x > 1280 ){
        
        this->pRed++;
        this->pointsRed->setPoints(this->pRed);
        this->ball.setPosition(610,300);

    }
    if(this->ball.getPosition().x < 10){
        this->pBlue++;
        this->pointsBlue->setPoints(this->pBlue);
        this->ball.setPosition(610,300);
    }

    if(this->pRed == 11 || this->pBlue == 11){
        this->ball.setPosition(100,100);
        this->xVelocity = 0;
        this->yVelocity =0;
    }

}

sf::Vector2f Ball::getPosition()
{
    this->pos.x = this->ball.getPosition().x;
    this->pos.y = this->ball.getPosition().y;
    return pos;
}

float Ball::getRadius()
{
    return this->ball.getRadius();
}

void Ball::setPosition(float x, float y)
{
    this->pos.x = x;
    this->pos.y = y;
    this->ball.setPosition(this->pos);
}