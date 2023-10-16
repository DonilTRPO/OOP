#include "rectangle.hpp"

Rectangle::Rectangle(sf::Vector2f _size) : Shape() {
    setSize(_size);
}

Rectangle::Rectangle(float _w, float _h) : Shape() {
    setSize(_w, _h);
}

Rectangle::Rectangle() : Shape() {
    setSize(20, 10);
}

void Rectangle::updatePoints() {
    if (getPointCount() != 4) Shape::setPointCount(4);
    Shape::setPoint(0, sf::Vector2f(0, 0));
    Shape::setPoint(1, sf::Vector2f(size.x, 0));
    Shape::setPoint(2, sf::Vector2f(size.x, size.y));
    Shape::setPoint(3, sf::Vector2f(0, size.y));
}

void Rectangle::setSize(sf::Vector2f _size) {
    size.x = (_size.x) ? _size.x : 0;
    size.y = (_size.y) ? _size.y : 0;

    updatePoints();
}

void Rectangle::setSize(float _w, float _h) {
    size.x = (_w) ? _w : 0;
    size.y = (_h) ? _h : 0;

    updatePoints();
}

sf::Vector2f Rectangle::getSize(void) {
    return size;
}