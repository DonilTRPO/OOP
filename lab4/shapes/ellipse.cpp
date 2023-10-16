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