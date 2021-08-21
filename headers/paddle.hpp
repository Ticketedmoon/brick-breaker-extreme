#pragma once
#ifndef BRICK_BREAKER_EXTREME_PADDLE_HPP
#define BRICK_BREAKER_EXTREME_PADDLE_HPP

#include <SFML/Graphics/RectangleShape.hpp>

class Paddle {

private:
    sf::RectangleShape rectangle;
    float velocity = 3.0;
    float x;
    float y;

public:
    Paddle();
    Paddle(float width, float height, float x, float y);
    sf::RectangleShape getRectangleShapeForPaddle();
    void moveLeft();
    void moveRight();
};

#endif //BRICK_BREAKER_EXTREME_PADDLE_HPP