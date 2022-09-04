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
    static void destroyBrick(int brickIndex); // TODO: This probably should be in a different class (We should think about moving the bricks vector out of Engine.
};
