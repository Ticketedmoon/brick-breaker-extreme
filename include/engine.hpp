#pragma once

#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "constants.hpp"
#include "utils.hpp"

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
    std::vector<Brick> createBricks();
    void showViewOnGameStateChange(std::string text, sf::Color backgroundColor, sf::Color textColor);

public:
    Engine();
    void draw();
    void run();
    static void destroyBrick(int brickIndex); // TODO: This probably should be in a different class (We should think about moving the bricks vector out of Engine.
};
