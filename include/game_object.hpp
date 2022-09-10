#pragma once

class GameObject {

protected:
    float x;
    float y;

public:
    float getX();
    void setX(float x);

    float getY();
    void setY(float y);
};