#include "line.hpp"

Line::Line(float _length, float _thickness) : Shape() {
    length = (_length) ? _length : 0;
    thickness = (_thickness) ? _thickness : 0;
    updatePoints();
}

Line::Line(float _l) : Shape() {
    length = (_l) ? _l : 0;
    thickness = 3;
    updatePoints();
}

Line::Line() : Shape() {
    length = 10;
    thickness = 3;
    updatePoints();
}

void Line::updatePoints() {
    if (getPointCount() != 4) Shape::setPointCount(4);
    Shape::setPoint(0, sf::Vector2f(0, 0));
    Shape::setPoint(1, sf::Vector2f(length, 0));
    Shape::setPoint(2, sf::Vector2f(length, thickness));
    Shape::setPoint(3, sf::Vector2f(0, thickness));
}

void Line::setLength(float _l) {
    length = (_l) ? _l : 0;
    updatePoints();
}

float Line::getLength(void) {
    return length;
}

void Line::setThickness(float _thickness) {
    thickness = (_thickness) ? _thickness : 0;
    updatePoints();
}

float Line::getThickness(void) {
    return thickness;
}