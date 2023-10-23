#include "rhombus.hpp"

Rhombus::Rhombus(sf::Vector2f _size) : Shape() {
    setSize(_size);
}

Rhombus::Rhombus(float _w, float _h) : Shape() {
    setSize(_w, _h);
}

Rhombus::Rhombus() : Shape() {
    setSize(20, 10);
}

void Rhombus::updatePoints() {
    if (getPointCount() != 4) Shape::setPointCount(4);
    Shape::setPoint(0, sf::Vector2f(size.x / 2, 0));
    Shape::setPoint(1, sf::Vector2f(size.x, size.y / 2));
    Shape::setPoint(2, sf::Vector2f(size.x / 2, size.y));
    Shape::setPoint(3, sf::Vector2f(0, size.y / 2));
}

void Rhombus::setSize(sf::Vector2f _size) {
    size.x = (_size.x) ? _size.x : 0;
    size.y = (_size.y) ? _size.y : 0;

    updatePoints();
}

void Rhombus::setSize(float _w, float _h) {
    size.x = (_w) ? _w : 0;
    size.y = (_h) ? _h : 0;

    updatePoints();
}

sf::Vector2f Rhombus::getSize(void) {
    return size;
}

void Rhombus::move(sf::Vector2i win, sf::Vector2f offset) {
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

void Rhombus::move(int winX, int winY, float offsetX, float offsetY) {
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}

void Rhombus::move(sf::Vector2i win, float offsetX, float offsetY) {
    move(win, sf::Vector2f(offsetX, offsetY));
}

void Rhombus::move(int winX, int winY, sf::Vector2f offset) {
    move(sf::Vector2i(winX, winY), offset);
}

void Rhombus::rotate(float _ang) {
    setRotation(getRotation() + _ang);
}

