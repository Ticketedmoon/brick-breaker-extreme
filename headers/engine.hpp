#ifndef BRICK_BREAKER_EXTREME_ENGINE_HPP
#define BRICK_BREAKER_EXTREME_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using sf::Time;
using sf::Vector2f;
using sf::RenderWindow;
using sf::VideoMode;
using sf::seconds;
using sf::Color;

class Engine {

private:
    const unsigned int FPS = 60;
    static const Time TimePerFrame;

    Vector2f resolution;
    RenderWindow window;

public:
    Engine();
    void draw();
    void run();
};


#endif //BRICK_BREAKER_EXTREME_ENGINE_HPP
