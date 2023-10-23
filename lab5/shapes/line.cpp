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

void Line::move(sf::Vector2i win, sf::Vector2f offset) {
    setPosition(getPosition() + offset);    // from orig move() method

    sf::FloatRect boundingBox = getGlobalBounds();
    if (boundingBox.left + boundingBox.width > win.x || boundingBox.left < 0) {
        setSpeed(getSpeed().x * -1, getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
        setPosition(getPosition() + offset);
    }
    if (boundingBox.top + boundingBox.height > win.y || boundingBox.top < 0) {
        setSpeed(getSpeed().x, getSpeed().y * -1);
        offset.y *= -1;
        offset.x = 0;
        setPosition(getPosition() + offset);
    }
}

void Line::move(int winX, int winY, float offsetX, float offsetY) {
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}

void Line::move(sf::Vector2i win, float offsetX, float offsetY) {
    move(win, sf::Vector2f(offsetX, offsetY));
}

void Line::move(int winX, int winY, sf::Vector2f offset) {
    move(sf::Vector2i(winX, winY), offset);
}

void Line::rotate(float _ang) {
    setRotation(getRotation() + _ang);
}

