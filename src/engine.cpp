#include "engine.hpp"
#include "brick.hpp"
#include "constants.hpp"
#include <iostream>
#include <stdlib.h>

Ball ball;
Paddle paddle;

std::vector<Brick> bricks(32, Brick());

const int BRICK_WIDTH = 160;
const int BRICK_HEIGHT = 40;
const int TOTAL_BRICKS_PER_ROW = constants::WINDOW_WIDTH / BRICK_WIDTH;
const int TOTAL_BRICK_ROWS = bricks.size() / TOTAL_BRICKS_PER_ROW;

Engine::Engine() 
{
    // Window
    resolution = sf::Vector2i(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT);
    window.create(sf::VideoMode(resolution.x, resolution.y), "Brick Breaker Extreme", sf::Style::Titlebar);

	auto desktop = sf::VideoMode::getDesktopMode();
    
	window.setPosition(sf::Vector2i(desktop.width/2 - constants::X_SCREEN_LOCATION_OFFSET, desktop.height/2 - constants::Y_SCREEN_LOCATION_OFFSET));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FPS);

    // Fonts
    bool wasSuccessfullyLoaded = font.loadFromFile("./assets/fonts/totally_different.ttf");
    // Must be loaded relative to where the executable is.
    if (!wasSuccessfullyLoaded) 
    {
        throw std::runtime_error("Font failed to load");
    }

    // Create paddle
    paddle = Engine::createPaddle();

    // Create ball
    ball = Engine::createBall();

    // Create bricks
    // TODO: Convert me into private method.
	std::cout << "Creating bricks\n";
	for (int i = 0; i < TOTAL_BRICK_ROWS; i++) 
	{
		for (int j = 0; j < TOTAL_BRICKS_PER_ROW; j++)
		{
			int xPos = j * BRICK_WIDTH;
			int yPos = 20 + (i * BRICK_HEIGHT);
			int r = rand() % 255; 
			int g = rand() % 255;
			int b = rand() % 255;
 			sf::Color color = sf::Color(r, g, b);
			int brickIndex = (i * TOTAL_BRICKS_PER_ROW) + j;
			bricks[brickIndex] = Brick(BRICK_WIDTH, BRICK_HEIGHT, xPos, yPos, color);
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
        this->draw();
    }
}

void Engine::draw() 
{
    this->window.clear(sf::Color::Blue);
    if (isPlaying) {
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
        for (int i = 0; i < bricks.size(); i++)
        {
            this->window.draw(bricks[i].getRectangleShapeForBrick());
        }
        this->isPlaying = ball.play(paddle, bricks, resolution);
    } else {
        this->showGameOverView();
    }
    this->window.display();
}

void Engine::destroyBrick(int brickIndex)
{
	std::vector<Brick>::iterator brickIndexToRemove = bricks.begin() + brickIndex;
	bricks.erase(brickIndexToRemove);
	std::cout << "bricks size: " << bricks.size() << '\n';
}

Paddle Engine::createPaddle() {
    const float paddleWidth = 500.f;
    const float paddleHeight = 10.f;
    float paddleXPosition = (window.getSize().x / 2.f) - (paddleWidth / 2.f);
    float paddleYPosition = window.getSize().y - 100.f;
    return Paddle(paddleWidth, paddleHeight, paddleXPosition, paddleYPosition);
}

Ball Engine::createBall() {
    const float ballRadius = 20.f;
    float ballStartX = (window.getSize().x / 2.f) - ballRadius;
    float ballStartY = (window.getSize().y / 2.f) - ballRadius;
    return Ball(ballRadius, ballStartX, ballStartY, destroyBrick);
}

void Engine::showGameOverView() {
    sf::Text text = sf::Text("Game Over!\nPress [SPACE] to restart", font);
    // set the character size
    text.setCharacterSize(128); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color::Red);
    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setPosition(constants::WINDOW_WIDTH/2 - bounds.width/2, 225);
    // inside the main loop, between window.clear() and window.display()
    window.draw(text);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
    {
        this->isPlaying = true;
        ball = createBall();
        paddle = createPaddle();
    }
}