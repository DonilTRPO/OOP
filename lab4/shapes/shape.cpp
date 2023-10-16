#include "shape.hpp"

Shape::Shape() : sf::ConvexShape() {
    speed.x = 0;
    speed.y = 0;
}

void Shape::setSpeed(sf::Vector2f _speed) {
    speed = _speed;
}

void Shape::setSpeed(float _x, float _y) {
    setSpeed(sf::Vector2f(_x, _y));
}

sf::Vector2f Shape::getSpeed(void) {
    return speed;
}

void Shape::move(sf::Vector2i win, sf::Vector2f offset) {
    setPosition(getPosition() + offset);

    sf::FloatRect boundingBox = getGlobalBounds();
    if (boundingBox.left + boundingBox.width > win.x || boundingBox.left < 0) {
        speed.x *= -1;
        offset.x *= -1;
        offset.y = 0;
        setPosition(getPosition() + offset);
    }
    if (boundingBox.top + boundingBox.height > win.y || boundingBox.top < 0) {
        speed.y *= -1;
        offset.y *= -1;
        offset.x = 0;
        setPosition(getPosition() + offset);
    }
}

void Shape::move(int winX, int winY, float offsetX, float offsetY) {
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}

void Shape::move(sf::Vector2i win, float offsetX, float offsetY) {
    move(win, sf::Vector2f(offsetX, offsetY));
}

void Shape::move(int winX, int winY, sf::Vector2f offset) {
    move(sf::Vector2i(winX, winY), offset);
}

void Shape::rotate(float _ang) {
    setRotation(getRotation() + _ang);
}