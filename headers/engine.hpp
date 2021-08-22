#pragma once

#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "ball.hpp"

class Engine {

private:
    const unsigned int FPS = 60;
    sf::Vector2i resolution;
    sf::RenderWindow window;

public:
    Engine();
    void draw();
    void run();
};