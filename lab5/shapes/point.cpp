#include "point.hpp"

#define POINT_RADIUS 5

Point::Point() : Circle() {
    Circle::setRadius(POINT_RADIUS);
}

float Point::getRadius() {
    return POINT_RADIUS;
}

void Point::move(sf::Vector2i win, sf::Vector2f offset) {
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

void Point::move(int winX, int winY, float offsetX, float offsetY) {
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}

void Point::move(sf::Vector2i win, float offsetX, float offsetY) {
    move(win, sf::Vector2f(offsetX, offsetY));
}

void Point::move(int winX, int winY, sf::Vector2f offset) {
    move(sf::Vector2i(winX, winY), offset);
}

void Point::rotate(float _ang) {
    setRotation(getRotation() + _ang);
}

