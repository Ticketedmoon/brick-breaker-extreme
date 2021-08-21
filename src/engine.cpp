#include "engine.hpp"
#include <iostream>

// Ball::ball;
Paddle paddle;

Engine::Engine() {
    resolution = sf::Vector2i(800, 600);
    window.create(sf::VideoMode(resolution.x, resolution.y), "Brick Breaker Extreme", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FPS);

    const float paddleWidth = 80.f;
    const float paddleHeight = 10.f;
    float paddleXPosition = -(window.getSize().x / 2.f) + paddleWidth / 2.f;
    float paddleYPosition = -(window.getSize().y - 100.f);
    paddle = Paddle(paddleWidth, paddleHeight, paddleXPosition, paddleYPosition);

    const float ballRadius = 80.f;
    float ballX = -(window.getSize().x / 2.f) + paddleWidth / 2.f;
    float ballY = -(window.getSize().y - 100.f);
    //ball = Ball();
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

    this -> window.draw(paddle.getRectangleShapeForPaddle());
    this -> window.display();
}