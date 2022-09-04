#include "engine.hpp"
#include "brick.hpp"
#include "constants.hpp"
#include <iostream>
#include <stdlib.h>

Ball ball;
Paddle paddle;

std::vector<Brick> bricks;

Engine::Engine() 
{
    resolution = sf::Vector2i(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT);
    window.create(sf::VideoMode(resolution.x, resolution.y), "Brick Breaker Extreme", sf::Style::Titlebar);

	auto desktop = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i(desktop.width/2 - constants::X_SCREEN_LOCATION_OFFSET, desktop.height/2 - constants::Y_SCREEN_LOCATION_OFFSET));

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
    ball = Ball(ballRadius, ballStartX, ballStartY, destroyBrick);

	std::cout << "Creating bricks\n";
    // Create bricks
	
	for (int i = 0; i < constants::TOTAL_BRICK_ROWS; i++) 
	{
		for (int j = 0; j < constants::TOTAL_BRICKS_PER_ROW; j++)
		{
			int xPos = j * constants::BRICK_WIDTH;
			int yPos = 20 + (i * constants::BRICK_HEIGHT);
			int r = rand() % 255; 
			int g = rand() % 255;
			int b = rand() % 255;
 			sf::Color color = sf::Color(r, g, b);
			int brickIndex = (i * constants::TOTAL_BRICKS_PER_ROW) + j;
			bricks.push_back(Brick(constants::BRICK_WIDTH, constants::BRICK_HEIGHT, xPos, yPos, color));
		}
	}	
}

// Note: Run until window is closed
void Engine::run() 
{
    while (window.isOpen()) 
	{
        // Check for any event on the window
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch (event.type) 
			{
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

void Engine::draw() 
{
    this->window.clear(sf::Color::Blue);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	{
        paddle.moveLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
        paddle.moveRight();
    }

    this->window.draw(paddle.getRectangleShapeForPaddle());
    this->window.draw(ball.getCircleShapeForBall());
	for (int i = 0; i < constants::TOTAL_BRICKS; i++)
	{
    	this->window.draw(bricks[i].getRectangleShapeForBrick());
	}
    ball.play(paddle, bricks);
    this->window.display();
}

void Engine::destroyBrick(int brickIndex)
{
	std::vector<Brick>::iterator brickIndexToRemove = bricks.begin() + brickIndex;
	std::cout << "bricks size: " << bricks.size() << '\n';
	bricks.erase(brickIndexToRemove);
	std::cout << "bricks size: " << bricks.size() << '\n';
}
