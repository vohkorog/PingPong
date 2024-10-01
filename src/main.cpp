#include <iostream>
#include "window.hpp"

int main()
{
    Window window(1280, 720, "Pin Pong");

    while(window.running()){
        window.update();
        window.render();
    }
}