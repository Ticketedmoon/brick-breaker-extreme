#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Audio.hpp>

#include "game_object.hpp"
#include "brick.hpp"
#include "paddle.hpp"
#include "constants.hpp"
#include "game_object.hpp"
#include "audio_manager.hpp"

class Ball : public GameObject {

private:
    float radius;
    float velocityX = 10.0;
    float velocityY = 7.5;
    int direction = 1;

    sf::CircleShape ballShape;
    sf::SoundBuffer ballBrickTouchSoundBuffer; 
    sf::Sound ballBrickTouchSound; 

public:
    Ball();
    Ball(float radius, float x, float y);

    sf::CircleShape getCircleShapeForBall();
    void startMovement(); 
    void playBrickDestroySound();
    
    float getVelocityX();
    float getVelocityY();
    int getDirection();
    float getRadius();

    void setVelocityX(float velocity);
    void setVelocityY(float velocity);
    void setDirection(int direction);
};
