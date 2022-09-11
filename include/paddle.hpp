#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "game_object.hpp"
#include "constants.hpp"

const float PADDLE_OUTLINE_THICKNESS = 3.0f;

class Paddle : public GameObject 
{
private:
    sf::RectangleShape rectangle;
    float velocity = 15.0;
    float width;
    float height;

public:
    Paddle();
    Paddle(float width, float height, float x, float y);
    sf::RectangleShape getRectangleShapeForPaddle();
    void moveLeft();
    void moveRight();
    float getWidth();
    float getHeight();
};
