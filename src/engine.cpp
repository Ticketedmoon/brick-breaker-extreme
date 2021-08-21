#include "engine.hpp"
#include <iostream>

const sf::Time Engine::TimePerFrame = sf::seconds(1.5/60.f);

Engine::Engine() {
    resolution = sf::Vector2i(800, 600);
    window.create(sf::VideoMode(resolution.x, resolution.y), "Brick Breaker Extreme", sf::Style::Default);
    window.setFramerateLimit(FPS);
}

// Note: Run until window is closed
void Engine::run() {
    while (window.isOpen()) {
        // Check for any event on the window
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "Mouse pressed inside window" << std::endl;
            }
        }
        draw();
    }
}
