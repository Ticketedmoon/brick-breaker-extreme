#include <iostream>
#include "ball.hpp"

Ball::Ball() = default;

Ball::Ball(float radius, float x, float y) {
    this -> x = x;
    this -> y = y;
    this -> ball = sf::CircleShape(radius);
    this -> ball.setOrigin(x, y);
}

void Ball::play() {
    std::cout << "Starting Game..." << std::endl;
}
