#pragma once
#ifndef BRICK_BREAKER_EXTREME_PADDLE_HPP
#define BRICK_BREAKER_EXTREME_PADDLE_HPP

#include <SFML/Graphics/CircleShape.hpp>

class Ball {

private:
    sf::CircleShape ball;
    const float velocity = 7.0;
    float x{};
    float y{};

public:
    Ball();
    Ball(float radius, float x, float y);
    void play();
};

#endif //BRICK_BREAKER_EXTREME_PADDLE_HPP