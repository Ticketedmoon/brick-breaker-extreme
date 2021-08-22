#include "engine.hpp"
#include "brick.hpp"
#include <iostream>

Ball ball;
Paddle paddle;

const int totalBricks = 1;
Brick bricks[totalBricks];

Engine::Engine() {
    resolution = sf::Vector2i(800, 600);
    window.create(sf::VideoMode(resolution.x, resolution.y), "Brick Breaker Extreme", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FPS);

    // Create paddle
    const float paddleWidth = 80.f;
    const float paddleHeight = 10.f;
    float paddleXPosition = (window.getSize().x / 2.f) - (paddleWidth / 2.f);
    float paddleYPosition = window.getSize().y - 100.f;
    paddle = Paddle(paddleWidth, paddleHeight, paddleXPosition, paddleYPosition);

    // Create ball
    const float ballRadius = 20.f;
    float ballStartX = (window.getSize().x / 2.f) - ballRadius;
    float ballStartY = (window.getSize().y / 2.f) - ballRadius;
    ball = Ball(ballRadius, ballStartX, ballStartY);

    // Create bricks
    for (int i = 0; i < totalBricks; i++)
    {
        bricks[i] = Brick(120, 40, (window.getSize().x / 2.f), 20, sf::Color::Red);
    }
}

// Note: Run until window is closed
void Engine::run() {
    while (window.isOpen()) {
        // Check for any event on the window
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::LostFocus:
                        std::cout << "Pause game now since focus to window lost" << std::endl;
                        break;
                case sf::Event::GainedFocus:
                    std::cout << "Resume game now since focus to window Regained" << std::endl;
                    break;
            }
        }
        draw();
    }
}

void Engine::draw() {
    this -> window.clear(sf::Color::Blue);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        paddle.moveLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        paddle.moveRight();
    }

    this->window.draw(paddle.getRectangleShapeForPaddle());
    this->window.draw(ball.getCircleShapeForBall());
    this->window.draw(bricks[0].getRectangleShapeForBrick());

    ball.play(paddle, bricks);
    this->window.display();
}