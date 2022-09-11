#pragma once

#include "game_object.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class Brick : public GameObject {
private:
    sf::Color colour;
    sf::RectangleShape rectangle;

public:
    Brick();
    Brick(float width, float height, float x, float y, sf::Color colour);
    sf::RectangleShape getRectangleShapeForBrick();
    float getWidth();
};
