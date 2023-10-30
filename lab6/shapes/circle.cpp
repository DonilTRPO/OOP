#include "circle.hpp"

#include <cmath>
#include <iostream>

Circle::Circle(float _radius) : Shape() {
    setRadius(_radius);
}

Circle::Circle() : Shape() {
    setRadius(10);
}

void Circle::updatePoints() {
    if (getPointCount() != pointCount) Shape::setPointCount(pointCount);

    float rad, x, y;
    for (int i = 0; i < pointCount; i++) {
        rad = (360 / pointCount * i) / (360 / M_PI / 2);
        x = cos(rad) * radius;
        y = sin(rad) * radius;
        Shape::setPoint(i, sf::Vector2f(x, y));
    }
}

void Circle::setRadius(float _radius) {
    radius = (_radius) ? _radius : 0;
    updatePoints();
}

float Circle::getRadius(void) {
    return radius;
}

void Circle::setOriginAtCenter() {
    this->setOrigin(0, 0);
}

void Circle::move(sf::Vector2i win, sf::Vector2f offset) {
    setPosition(getPosition() + offset);    // from orig move() method

    sf::FloatRect boundingBox = getGlobalBounds();
    if (boundingBox.left + boundingBox.width > win.x || boundingBox.left < 0) {
        setSpeed(getSpeed().x * -1, getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
        setPosition(getPosition() + offset);
        std::cout << "Circle is bounced off horizontal border at pos(" << this->getPosition().x << ", " << this->getPosition().y << ")" << std::endl;
    }
    if (boundingBox.top + boundingBox.height > win.y || boundingBox.top < 0) {
        setSpeed(getSpeed().x, getSpeed().y * -1);
        offset.y *= -1;
        offset.x = 0;
        setPosition(getPosition() + offset);
        std::cout << "Circle is bounced off vertical border at pos(" << this->getPosition().x << ", " << this->getPosition().y << ")" << std::endl;
    }
}

void Circle::move(int winX, int winY, float offsetX, float offsetY) {
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}

void Circle::move(sf::Vector2i win, float offsetX, float offsetY) {
    move(win, sf::Vector2f(offsetX, offsetY));
}

void Circle::move(int winX, int winY, sf::Vector2f offset) {
    move(sf::Vector2i(winX, winY), offset);
}

void Circle::rotate(float _ang) {
    setRotation(getRotation() + _ang);
}

