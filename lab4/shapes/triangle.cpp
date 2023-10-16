#include "triangle.hpp"

Triangle::Triangle(float _side) : Shape() {
    setSide(_side);
}

Triangle::Triangle() : Shape() {
    setSide(15);
}

void Triangle::updatePoints() {
    if (getPointCount() != 3) Shape::setPointCount(3);
    Shape::setPoint(0, sf::Vector2f(0, side));
    Shape::setPoint(1, sf::Vector2f(side / 2, 0));
    Shape::setPoint(2, sf::Vector2f(side, side));
}

void Triangle::setSide(float _side) {
    side = (_side) ? _side : 0;
    updatePoints();
}

float Triangle::getSide(void) {
    return side;
}