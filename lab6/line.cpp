#include "line.hpp"

#include <iostream>

Line::Line(float _length, float _thickness) : Shape() {
    this->setSize(_length, _thickness);
}

Line::Line(float _length) : Shape() {
    this->setSize(_length, 3);
}

Line::Line(sf::Vector2f _size) : Shape() {
    this->setSize(_size);
}

Line::Line() : Shape() {
    this->setSize(10, 3);
}

void Line::updatePoints() {
    if (getPointCount() != 4) Shape::setPointCount(4);
    Shape::setPoint(0, sf::Vector2f(0, 0));
    Shape::setPoint(1, sf::Vector2f(length, 0));
    Shape::setPoint(2, sf::Vector2f(length, thickness));
    Shape::setPoint(3, sf::Vector2f(0, thickness));
}

void Line::setSize(float _length, float _thickness) {
    this->length = (_length) ? _length : 0;
    this->thickness = (_thickness) ? _thickness : 0;
    this->updatePoints();
}

void Line::setSize(sf::Vector2f _size) {
    this->length = (_size.x) ? _size.x : 0;
    this->thickness = (_size.y) ? _size.y : 0;
    this->updatePoints();
}

sf::Vector2f Line::getSize() {
    return sf::Vector2f(this->length, this->thickness);
}

void Line::setOriginAtCenter() {
    setOrigin(this->getSize().x / 2, this->getSize().y / 2);
}

void Line::move(sf::Vector2i win, sf::Vector2f offset) {
    setPosition(getPosition() + offset);    // from orig move() method

    sf::FloatRect boundingBox = getGlobalBounds();
    if (boundingBox.left + boundingBox.width > win.x || boundingBox.left < 0) {
        setSpeed(getSpeed().x * -1, getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
        setPosition(getPosition() + offset);
        std::cout << "Line is bounced off horizontal border at pos(" << this->getPosition().x << ", " << this->getPosition().y << ")" << std::endl;
    }
    if (boundingBox.top + boundingBox.height > win.y || boundingBox.top < 0) {
        setSpeed(getSpeed().x, getSpeed().y * -1);
        offset.y *= -1;
        offset.x = 0;
        setPosition(getPosition() + offset);
        std::cout << "Line is bounced off vertical border at pos(" << this->getPosition().x << ", " << this->getPosition().y << ")" << std::endl;
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
