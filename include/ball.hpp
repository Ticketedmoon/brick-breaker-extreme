#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "brick.hpp"
#include "paddle.hpp"

class Ball {

private:
    sf::CircleShape ball;
    float velocityX = 5.0;
    float velocityY = 5.0;
    float x;
    float y;
	void (*destroyBrick)(int);

public:

    Ball();
    Ball(float radius, float x, float y, void (*destroyBrick)(int));

    sf::CircleShape getCircleShapeForBall();
    void updateVelocityX();
    void updateVelocityY();
    bool play(Paddle paddle, std::vector<Brick>& bricks, sf::Vector2i resoution);
    void checkForPaddleTouch(Paddle& paddle);
    void checkForBrickTouch(std::vector<Brick>& bricks);
    
    float getX();
    float getY();
};
