#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class Brick {
private:
    sf::Color colour;
    sf::RectangleShape rectangle;
    float x;
    float y;
    float width;

public:
    Brick();
    Brick(float width, float height, float x, float y, sf::Color colour);
    sf::RectangleShape getRectangleShapeForBrick();
    float getX();
    float getWidth();
};
