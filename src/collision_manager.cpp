#include "collision_manager.hpp"

using namespace constants;

GameState CollisionManager::checkForWindowBorderCollision(Ball& ball)
{
    bool isTouchingDeathZoneBottomBorder = ball.getY() >= WINDOW_HEIGHT - WINDOW_STANDARD_OFFSET_FOR_BALL_COLLISION;
    if (isTouchingDeathZoneBottomBorder) 
    {
        return GameState::GAMEOVER;
    }

    bool isTouchingLeftOrRightBorder = ball.getX() <= 0 
        || ball.getX() >= WINDOW_WIDTH-WINDOW_STANDARD_OFFSET_FOR_BALL_COLLISION;
    bool isTouchingTopBorder = (ball.getY() <= 0);
    
    if (isTouchingLeftOrRightBorder) 
    {
        ball.setVelocityX(-ball.getVelocityX());
        int newDirection = ball.getDirection() * -1;
        ball.setDirection(newDirection);
    } 
    if (isTouchingTopBorder)
    {
        ball.setVelocityY(-ball.getVelocityY());
    }
    return GameState::PLAYING;
}

void CollisionManager::checkForBrickTouch(Ball& ball, std::vector<Brick>& bricks) 
{
    for (int i = 0; i < bricks.size(); i++)
    {
        Brick* brick = &bricks.at(i);
        float tolerance = 10.0;
		bool isBallAfterBrickStartX = brick->getRectangleShapeForBrick().getPosition().x <= (ball.getX()+ball.getRadius());
		bool isBallBeforeBrickEndX = (brick->getRectangleShapeForBrick().getPosition().x + brick->getWidth()) >= ball.getX();
        bool isTouchingBrickX = isBallAfterBrickStartX && isBallBeforeBrickEndX;
        bool isTouchingBrickY = (ball.getY() - brick->getRectangleShapeForBrick().getPosition().y) <= tolerance;
        if (isTouchingBrickY && isTouchingBrickX)
        {
        	ball.setVelocityY(-ball.getVelocityY());
            ball.playBrickDestroySound();
            std::vector<Brick>::iterator brickIndexToRemove = bricks.begin() + i;
            bricks.erase(brickIndexToRemove);
            std::cout << "brick ID: " << i << std::endl;
            std::cout << "bricks size: " << bricks.size() << '\n';
        }
    }
}

void CollisionManager::checkForPaddleTouch(Paddle& paddle, Ball& ball) 
{
    int diameter = ball.getRadius() * 2;
    float paddleX = paddle.getRectangleShapeForPaddle().getPosition().x;
    float paddleY = paddle.getRectangleShapeForPaddle().getPosition().y;

    bool isTouchingPaddleX = (
        (paddleX <= ball.getX() + diameter) &&
        (paddleX + paddle.getWidth()) >= ball.getX());
    bool isTouchingPaddleY = (paddleY <= ball.getY() + diameter)
        && (paddleY + paddle.getHeight() >= ball.getY());

    if (isTouchingPaddleY && isTouchingPaddleX)
    {
        bool touchRight = (ball.getX() >= paddle.getRectangleShapeForPaddle().getPosition().x + paddle.getWidth() / 2)
            && (ball.getX() <= paddle.getRectangleShapeForPaddle().getPosition().x + paddle.getWidth());
        bool isMovingRight = ball.getDirection() == 1;

        if (touchRight) 
        {
            if (isMovingRight) 
            {
                ball.setVelocityX(ball.getVelocityX() - 3);
            } else 
            {
                ball.setVelocityX(ball.getVelocityX() + 3);
            }
        } 
		else 
        {
            if (isMovingRight) 
            {
                ball.setVelocityX(ball.getVelocityX() + 3);
            } 
            else 
            {
                ball.setVelocityX(ball.getVelocityX() - 3);
            }
        }
        ball.setVelocityY(ball.getVelocityY() * -1);
    }
}
