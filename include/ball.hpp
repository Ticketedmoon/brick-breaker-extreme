#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "brick.hpp"
#include "paddle.hpp"

class Ball {

private:
    sf::CircleShape ball;
    float velocity = 4.0;
    float x;
    float y;

public:
    Ball();
    Ball(float radius, float x, float y);
    sf::CircleShape getCircleShapeForBall();
    void updateVelocity();
    void play(Paddle paddle, Brick bricks[]);
    void checkForPaddleTouch(Paddle& paddle);
    void checkForBrickTouch(Brick bricks[]);
};
