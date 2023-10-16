#include "circle.hpp"

#include <cmath>

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
        rad = (360 / pointCount * i);
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