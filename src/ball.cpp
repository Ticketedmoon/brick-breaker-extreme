#include <iostream>
#include "ball.hpp"
#include "constants.hpp"

Ball::Ball() = default;

Ball::Ball(float radius, float x, float y, void (*destroyBrick)(int)) {
    this -> x = x;
    this -> y = y;
    this -> ball = sf::CircleShape(radius);
    this -> ball.setOutlineColor(sf::Color::Black);
    this -> ball.setOutlineThickness(2.0);
    this -> ball.setPosition(x, y);
	this -> destroyBrick = destroyBrick;
}

void Ball::play(Paddle paddle, std::vector<Brick>& bricks) {
    checkForPaddleTouch(paddle);
    checkForBrickTouch(bricks);
    y += velocity;
    this->ball.setPosition(x, y);
}

void Ball::checkForBrickTouch(std::vector<Brick>& bricks) {
    for (int i = 0; i < constants::TOTAL_BRICKS; i++)
    {
        Brick brick = bricks[i];
        float tolerance = 10.0;
		bool isBallAfterBrickStartX = brick.getRectangleShapeForBrick().getPosition().x <= (this->x+ball.getRadius());
		bool isBallBeforeBrickEndX = (brick.getRectangleShapeForBrick().getPosition().x + brick.getWidth()) >= this->x;
        bool isTouchingBrickX = isBallAfterBrickStartX && isBallBeforeBrickEndX;
        bool isTouchingBrickY = (y - brick.getRectangleShapeForBrick().getPosition().y) <= tolerance;
        if (isTouchingBrickY && isTouchingBrickX)
        {
        	updateVelocity();
			(*destroyBrick)(i);
        }
    }
}

void Ball::checkForPaddleTouch(Paddle& paddle) {
    float tolerance = 35.0;
    bool isTouchingPaddleX = (
            (paddle.getRectangleShapeForPaddle().getPosition().x <= x) &&
            (paddle.getRectangleShapeForPaddle().getPosition().x + paddle.getX()) >= x);
    bool isTouchingPaddleY = (paddle.getRectangleShapeForPaddle().getPosition().y - y) <= tolerance;
    if (isTouchingPaddleY && isTouchingPaddleX)
    {
        updateVelocity();
    }
}

sf::CircleShape Ball::getCircleShapeForBall() {
    return this -> ball;
}

void Ball::updateVelocity() {
    this->velocity = -this->velocity;
}

