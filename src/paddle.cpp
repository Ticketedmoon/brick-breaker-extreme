#include "paddle.hpp"

Paddle::Paddle() = default;

Paddle::Paddle(float width, float height, float x, float y) {
    this -> rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    this -> rectangle.setOrigin(x, y);
}

sf::RectangleShape Paddle::getRectangleShapeForPaddle() {
    return rectangle;
}

void Paddle::moveLeft() {
    x -= velocity;
    this->rectangle.setPosition(x, this->y);
}

void Paddle::moveRight() {
    x += velocity;
    this->rectangle.setPosition(x, this->y);
}
