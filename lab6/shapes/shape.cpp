#include "shape.hpp"

Shape::Shape() : sf::ConvexShape() {
    speed.x = 0;
    speed.y = 0;
}

void Shape::setSpeed(sf::Vector2f _speed) {
    speed = _speed;
}

void Shape::setSpeed(float _x, float _y) {
    setSpeed(sf::Vector2f(_x, _y));
}

sf::Vector2f Shape::getSpeed(void) {
    return speed;
}
