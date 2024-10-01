#include "window.hpp"

void Window::initVar(){
    this->window = nullptr;
    this->playerOne = new Player(50, 240, sf::Color::Blue);
    this->playerTwo = new Player(1200, 240, sf::Color::Red);
    this->ball = new Ball(200,200);
}

void Window::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(this->screen_width, this->screen_height), this->title);
}

Window::Window(int width, int height, std::string title){
    this->screen_width = width;
    this->screen_height = height;
    this->title = title;
    initVar();
    initWindow();
}

Window::~Window(){
    delete this->window;
}

void Window::render(){
    this->window->clear(sf::Color(50,80,80,255));
    this->playerOne->render(this->window);
    this->playerTwo->render(this->window);
    this->ball->render(this->window);
    this->window->display();
}

void Window::update(){
    this->input();
    this->playerOne->input();
    this->playerTwo->input();
    this->ball->update(this->playerOne, this->playerTwo);
}

const bool Window::running() const {
    return this->window->isOpen();
}

void Window::input(){

    while (this->window->pollEvent(this->event))
        {
            if (event.type == sf::Event::Closed){
                this->window->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                this->window->close();
            }
        }
    
}