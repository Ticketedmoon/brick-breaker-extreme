#include "game_object.hpp"

float GameObject::getX() {
    return x;
}

float GameObject::getY() {
    return y;
}

void GameObject::setX(float x) {
    this->x = x;
}

void GameObject::setY(float y) {
    this->y = y;
}