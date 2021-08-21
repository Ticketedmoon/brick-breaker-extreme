#ifndef BRICK_BREAKER_EXTREME_ENGINE_HPP
#define BRICK_BREAKER_EXTREME_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "paddle.hpp"

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

#endif //BRICK_BREAKER_EXTREME_ENGINE_HPP