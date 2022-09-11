#include <iostream>
#include "ball.hpp"

Ball::Ball() = default;

Ball::Ball(float radius, float x, float y) 
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->ballShape = sf::CircleShape(radius);
    this->ballShape.setOutlineColor(sf::Color::Black);
    this->ballShape.setOutlineThickness(2.0);
    this->ballShape.setPosition(x, y);
    
    sf::SoundBuffer buffer = AudioManager::loadSfxFromFileIntoBuffer("./assets/sfx/water-droplet-sfx.ogg");
    this->ballBrickTouchSoundBuffer = buffer;
}

void Ball::startMovement() 
{
    this->x += velocityX;
    this->y -= velocityY;
    this->ballShape.setPosition(this->x, this->y);
}

void Ball::playBrickDestroySound()
{
    this->ballBrickTouchSound.setBuffer(ballBrickTouchSoundBuffer);
    this->ballBrickTouchSound.play();
}

sf::CircleShape Ball::getCircleShapeForBall() 
{
    return this->ballShape;
}

float Ball::getVelocityX() 
{
    return this->velocityX;
}

float Ball::getVelocityY() 
{
    return this->velocityY;
}

int Ball::getDirection()
{
    return this->direction;
}

float Ball::getRadius() 
{
    return this->ballShape.getRadius();
}

void Ball::setVelocityX(float velocity) 
{
    this->velocityX = velocity;
}

void Ball::setVelocityY(float velocity) 
{
    this->velocityY = velocity;
}

void Ball::setDirection(int newDirection) 
{
    this->direction = newDirection;
}