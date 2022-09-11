#include <iostream>
#include "paddle.hpp"

Paddle::Paddle() = default;

Paddle::Paddle(float width, float height, float x, float y) 
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    this->rectangle.setOutlineColor(sf::Color::Black);
    this->rectangle.setOutlineThickness(PADDLE_OUTLINE_THICKNESS);
    this->rectangle.setPosition(x, y);
}

sf::RectangleShape Paddle::getRectangleShapeForPaddle() 
{
    return rectangle;
}

void Paddle::moveLeft() 
{
    if (x >= PADDLE_OUTLINE_THICKNESS) // Account for the border outline
    {
        x -= velocity;
        this->rectangle.setPosition(x, this->y);
    }
}

void Paddle::moveRight() 
{

    if (x <= (constants::WINDOW_WIDTH-width-PADDLE_OUTLINE_THICKNESS))
    {
        x += velocity;
        this->rectangle.setPosition(x, this->y);
    }
}

float Paddle::getWidth() 
{
    return this->width;
}

float Paddle::getHeight() 
{
    return this->height;
}