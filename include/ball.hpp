#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "brick.hpp"
#include "paddle.hpp"

class Ball {

private:
    sf::CircleShape ball;
    float velocity = 10.0;
    float x;
    float y;
	void (*destroyBrick)(int);

public:
    Ball();
    Ball(float radius, float x, float y, void (*destroyBrick)(int));
    sf::CircleShape getCircleShapeForBall();
    void updateVelocity();
    void play(Paddle paddle, std::vector<Brick>& bricks);
    void checkForPaddleTouch(Paddle& paddle);
    void checkForBrickTouch(std::vector<Brick>& bricks);
};
