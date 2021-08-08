#include "engine.hpp"

const sf::Time Engine::TimePerFrame = seconds(1.5/60.f);

Engine::Engine() {
    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "Test Title", sf::Style::Default);
    window.setFramerateLimit(FPS);
}

// Note: Run until window is closed
void Engine::run() {
    while (window.isOpen()) {
        draw();
    }
}
