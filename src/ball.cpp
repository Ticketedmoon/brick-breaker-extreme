#include <iostream>
#include "ball.hpp"

Ball::Ball() = default;

Ball::Ball(float radius, float x, float y) {
    this -> x = x;
    this -> y = y;
    this -> ball = sf::CircleShape(radius);
    this -> ball.setOutlineColor(sf::Color::Black);
    this -> ball.setOutlineThickness(2.0);
    this -> ball.setPosition(x, y);
}

void Ball::play(Paddle paddle, Brick bricks[]) {
    checkForPaddleTouch(paddle);
    checkForBrickTouch(bricks);
    y += velocity;
    this->ball.setPosition(x, y);
}

void Ball::checkForBrickTouch(Brick bricks[]) {
    for (int i = 0; i < 1; i++)
    {
        Brick brick = bricks[i];
        float tolerance = 35.0;
        // TODO: Fix this expression
        bool isWithinBrickX = (
                brick.getRectangleShapeForBrick().getPosition().x <= (x+ball.getRadius()) &&
                (brick.getRectangleShapeForBrick().getPosition().x + brick.getX()) >= x);
        bool isTouchingBrickY = (y - brick.getRectangleShapeForBrick().getPosition().y) <= tolerance;
        std::cout << isWithinBrickX << ", " << isTouchingBrickY << std::endl;
        if (isTouchingBrickY && isWithinBrickX)
        {
            flipVelocity();
        }
    }
}

void Ball::checkForPaddleTouch(Paddle &paddle) {
    float tolerance = 35.0;
    bool isTouchingPaddleX = (
            (paddle.getRectangleShapeForPaddle().getPosition().x <= x) &&
            (paddle.getRectangleShapeForPaddle().getPosition().x + paddle.getX()) >= x);
    bool isTouchingPaddleY = (paddle.getRectangleShapeForPaddle().getPosition().y - y) <= tolerance;
    if (isTouchingPaddleY && isTouchingPaddleX)
    {
        flipVelocity();
    }
}

sf::CircleShape Ball::getCircleShapeForBall() {
    return this -> ball;
}

void Ball::flipVelocity() {
    this->velocity = -this->velocity;
}