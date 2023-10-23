#include "ellipse.hpp"

#include <cmath>

Ellipse::Ellipse(sf::Vector2f _radius) : Shape() {
    setRadius(_radius);
}

Ellipse::Ellipse(float _radiusX, float _radiusY) : Shape() {
    setRadius(_radiusX, _radiusY);
}

Ellipse::Ellipse() : Shape() {
    setRadius(10, 4);
}

void Ellipse::updatePoints() {
    if (getPointCount() != pointCount) Shape::setPointCount(pointCount);

    float rad, x, y;
    for (int i = 0; i < pointCount; i++) {
        rad = (360 / pointCount * i);
        x = cos(rad) * radius.x;
        y = sin(rad) * radius.y;
        Shape::setPoint(i, sf::Vector2f(x, y));
    }
}

void Ellipse::setRadius(sf::Vector2f _radius) {
    radius.x = (_radius.x) ? _radius.x : 0;
    radius.y = (_radius.y) ? _radius.y : 0;

    updatePoints();
}

void Ellipse::setRadius(float _radiusX, float _radiusY) {
    setRadius(sf::Vector2f(_radiusX, _radiusY));
}

sf::Vector2f Ellipse::getRadius(void) {
    return radius;
}

void Ellipse::move(sf::Vector2i win, sf::Vector2f offset) {
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

void Ellipse::move(int winX, int winY, float offsetX, float offsetY) {
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}

void Ellipse::move(sf::Vector2i win, float offsetX, float offsetY) {
    move(win, sf::Vector2f(offsetX, offsetY));
}

void Ellipse::move(int winX, int winY, sf::Vector2f offset) {
    move(sf::Vector2i(winX, winY), offset);
}

void Ellipse::rotate(float _ang) {
    setRotation(getRotation() + _ang);
}

