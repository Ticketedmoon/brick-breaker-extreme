#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "game_object.hpp"
#include "brick.hpp"
#include "paddle.hpp"
#include <SFML/Audio.hpp>
#include "audio_manager.hpp"

class Ball : public GameObject {

private:
    float radius;
    float velocityX = 10.0;
    float velocityY = 7.5;
    int direction = 1;

    sf::CircleShape ball;

    sf::SoundBuffer ballBrickTouchSoundBuffer; 
    sf::Sound ballBrickTouchSound; 

    void updateVelocityX(float velocity);
    void updateVelocityY(float velocity);
    bool checkForWindowBorderCollision(sf::Vector2i resolution);
    void checkForPaddleTouch(Paddle& paddle);
    void checkForBrickTouch(std::vector<Brick>& bricks);
	void (*destroyBrick)(int);

public:
    Ball();
    Ball(float radius, float x, float y, void (*destroyBrick)(int));

    sf::CircleShape getCircleShapeForBall();
    bool play(Paddle paddle, std::vector<Brick>& bricks, sf::Vector2i resoution);
    int getDirection();
    void setDirection(int direction);
};
