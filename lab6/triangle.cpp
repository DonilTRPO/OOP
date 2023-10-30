#include "triangle.hpp"

#include <iostream>

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

void Triangle::setOriginAtCenter() {
    this->setOrigin(this->getSide() / 2, this->getSide() / 2);
}

void Triangle::move(sf::Vector2i win, sf::Vector2f offset) {
    setPosition(getPosition() + offset);    // from orig move() method

    sf::FloatRect boundingBox = getGlobalBounds();
    if (boundingBox.left + boundingBox.width > win.x || boundingBox.left < 0) {
        setSpeed(getSpeed().x * -1, getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
        setPosition(getPosition() + offset);
        std::cout << "Triangle is bounced off horizontal border at pos(" << this->getPosition().x << ", " << this->getPosition().y << ")" << std::endl;
    }
    if (boundingBox.top + boundingBox.height > win.y || boundingBox.top < 0) {
        setSpeed(getSpeed().x, getSpeed().y * -1);
        offset.y *= -1;
        offset.x = 0;
        setPosition(getPosition() + offset);
        std::cout << "Triangle is bounced off vertical border at pos(" << this->getPosition().x << ", " << this->getPosition().y << ")" << std::endl;
    }
}

void Triangle::move(int winX, int winY, float offsetX, float offsetY) {
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}

void Triangle::move(sf::Vector2i win, float offsetX, float offsetY) {
    move(win, sf::Vector2f(offsetX, offsetY));
}

void Triangle::move(int winX, int winY, sf::Vector2f offset) {
    move(sf::Vector2i(winX, winY), offset);
}

void Triangle::rotate(float _ang) {
    setRotation(getRotation() + _ang);
}
