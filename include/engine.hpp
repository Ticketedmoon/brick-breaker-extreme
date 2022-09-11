#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

#include "paddle.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "utils.hpp"
#include "collision_manager.hpp"

class Engine
{
private:
    const unsigned int FPS = 60;
    GameState gameState = GameState::PLAYING;

    sf::Vector2i resolution;
    sf::RenderWindow window;
    sf::Font font;

    void onUpdate();
    void onRender();
    void onKeyboardEvent();

    Paddle createPaddle();
    Ball createBall();
    void createBricks();
    void showViewOnGameStateChange(std::string text, sf::Color backgroundColor, sf::Color textColor);

public:
    Engine();
    void draw();
    void run();
};
