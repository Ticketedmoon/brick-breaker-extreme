#include <iostream>
#include "ball.hpp"
#include "constants.hpp"

const int WINDOW_STANDARD_OFFSET_FOR_BALL_COLLISION = 20; 

Ball::Ball() = default;

Ball::Ball(float radius, float x, float y, void (*destroyBrick)(int)) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->ball = sf::CircleShape(radius);
    this->ball.setOutlineColor(sf::Color::Black);
    this->ball.setOutlineThickness(2.0);
    this->ball.setPosition(x, y);
	this->destroyBrick = destroyBrick;
}

bool Ball::play(Paddle paddle, std::vector<Brick>& bricks, sf::Vector2i resolution) 
{
    checkForPaddleTouch(paddle);
    checkForBrickTouch(bricks);

    // Window touch check
    bool isBallInFlight = checkForWindowBorderCollision(resolution);

    this->x += velocityX;
    this->y -= velocityY;

    this->ball.setPosition(this->x, this->y);
    return isBallInFlight;
}

bool Ball::checkForWindowBorderCollision(sf::Vector2i resolution) 
{
    
    bool isTouchingDeathZoneBottomBorder = this->y >= resolution.y - WINDOW_STANDARD_OFFSET_FOR_BALL_COLLISION;
    if (isTouchingDeathZoneBottomBorder) 
    {
        return false;
    }

    bool isTouchingLeftOrRightBorder = this->x <= -WINDOW_STANDARD_OFFSET_FOR_BALL_COLLISION || this->x >= resolution.x;
    bool isTouchTopBorder = (this->y <= 0);
    if (isTouchingLeftOrRightBorder) 
    {
        updateVelocityX(-velocityX);
        int newDirection = this->getDirection() * -1;
        this->setDirection(newDirection);
    } 
    if (isTouchTopBorder)
    {
        updateVelocityY(-velocityY);
    }
    return true;
}

void Ball::checkForBrickTouch(std::vector<Brick>& bricks) {
    for (int i = 0; i < bricks.size(); i++)
    {
        Brick brick = bricks[i];
        float tolerance = 10.0;
		bool isBallAfterBrickStartX = brick.getRectangleShapeForBrick().getPosition().x <= (this->x+ball.getRadius());
		bool isBallBeforeBrickEndX = (brick.getRectangleShapeForBrick().getPosition().x + brick.getWidth()) >= this->x;
        bool isTouchingBrickX = isBallAfterBrickStartX && isBallBeforeBrickEndX;
        bool isTouchingBrickY = (y - brick.getRectangleShapeForBrick().getPosition().y) <= tolerance;
        if (isTouchingBrickY && isTouchingBrickX)
        {
        	//updateVelocityX();
        	updateVelocityY(-velocityY);
            std::cout << "brick ID: " << i << std::endl;
			(*destroyBrick)(i);
        }
    }
}

void Ball::checkForPaddleTouch(Paddle& paddle) {
    bool isTouchingPaddleX = (
        (paddle.getRectangleShapeForPaddle().getPosition().x <= x) &&
        (paddle.getRectangleShapeForPaddle().getPosition().x + paddle.getWidth()) >= x);

    int paddleY = paddle.getRectangleShapeForPaddle().getPosition().y;

    // Offset is to account for the y position pointing to the top-left of the shape.
    // We need this to be the bottom so we hit the paddle correctly.
    // So add the radius * 2 for the diameter.
    int ballYPlusOffset = (this->y + this->radius * 2);

    bool isTouchingPaddleY = (paddleY - ballYPlusOffset) <= 0;
    if (isTouchingPaddleY && isTouchingPaddleX)
    {
        bool touchRight = (x >= paddle.getRectangleShapeForPaddle().getPosition().x + paddle.getWidth() / 2)
            && (x <= paddle.getRectangleShapeForPaddle().getPosition().x + paddle.getWidth());
        bool isMovingRight = getDirection() == 1;

        if (touchRight) {
            if (isMovingRight) {
                updateVelocityX(velocityX - 3);
            } else {
                updateVelocityX(velocityX + 3);
            }
        } else {
            if (isMovingRight) {
                 updateVelocityX(velocityX + 3);
            } else {
                updateVelocityX(velocityX - 3);
            }
        }
        updateVelocityY(velocityY * -1);
    }
}

sf::CircleShape Ball::getCircleShapeForBall() {
    return this->ball;
}

void Ball::updateVelocityX(float velocity) {
    this->velocityX = velocity;
}

void Ball::updateVelocityY(float velocity) {
    this->velocityY = velocity;
}

float Ball::getX() {
    return this->x;
}

float Ball::getY() {
    return this->y;
}

int Ball::getDirection() {
    return this->direction;
}

void Ball::setDirection(int newDirection) {
    this->direction = newDirection;
}