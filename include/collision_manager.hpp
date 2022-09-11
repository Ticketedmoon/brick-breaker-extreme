#pragma once

#include <iostream>
#include <stdlib.h>

#include "constants.hpp"
#include "brick.hpp"
#include "ball.hpp"
#include "paddle.hpp"

const int WINDOW_STANDARD_OFFSET_FOR_BALL_COLLISION = 20; 

class CollisionManager {
private:

public:
    static GameState checkForWindowBorderCollision(Ball& ball);
    static void checkForBrickTouch(Ball& ball, std::vector<Brick>& bricks);
    static void checkForPaddleTouch(Paddle& paddle, Ball& ball);
};