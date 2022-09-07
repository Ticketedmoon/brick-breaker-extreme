#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "brick.hpp"
#include "paddle.hpp"

class Ball {

private:
    sf::CircleShape ball;
    float velocityX = 10.0;
    float velocityY = 7.5;
    float x;
    float y;

    void updateVelocityX();
    void updateVelocityY();
    bool checkForWindowBorderCollision(sf::Vector2i resolution);
    void checkForPaddleTouch(Paddle& paddle);
    void checkForBrickTouch(std::vector<Brick>& bricks);
	void (*destroyBrick)(int);

public:
    Ball();
    Ball(float radius, float x, float y, void (*destroyBrick)(int));

    float getX();
    float getY();
    sf::CircleShape getCircleShapeForBall();
    bool play(Paddle paddle, std::vector<Brick>& bricks, sf::Vector2i resoution);
};
