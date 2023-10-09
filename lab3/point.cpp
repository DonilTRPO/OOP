#include "point.hpp"
#include "URNG.hpp"

#include <cmath>

void tPoint::updateConvexPoints() {
    short quality = 90;

    if (convex.getPointCount() != quality) convex.setPointCount(quality);
    convex.setOrigin(radius * -1, radius * -1);

    for (int i = 0; i < quality && radius; i++) {
        float rad = (360 / quality * i);
        float x = cos(rad) * radius;                                      // обновление формы точки
        float y = sin(rad) * radius;
        convex.setPoint(i, sf::Vector2f(x, y));
    }
}

tPoint::tPoint() {
    radius = 0;
    speed = sf::Vector2f(0, 0);
    dx = 1;
    dy = 1;
    convex.setPosition(sf::Vector2f(0, 0));                               // конструктор для инициализации точек
    convex.setFillColor(sf::Color::White);
    updateConvexPoints();
}

sf::ConvexShape tPoint::get_tPointConvex() {
    return convex;
}

void tPoint::set_tPointRadius(float _radius) {
    radius = _radius;
    updateConvexPoints();
}

float tPoint::get_tPointRadius() {
    return radius;
}

void tPoint::set_tPointSpeed(float _x, float _y) {
    speed = sf::Vector2f(_x, _y);
}

sf::Vector2f tPoint::get_tPointSpeed() {
    return speed;
}

void tPoint::set_tPointPosition(float _x, float _y) {
    convex.setPosition(sf::Vector2f(_x, _y));
    updateConvexPoints();
}

sf::Vector2f tPoint::get_tPointPosition() {
    return convex.getPosition();
}

void tPoint::set_tPointColor(int _r, int _g, int _b, int _alpha) {
    convex.setFillColor(sf::Color(_r, _g, _b, _alpha));
}

void tPoint::set_tPointColor(int _r, int _g, int _b) {
    convex.setFillColor(sf::Color(_r, _g, _b));
}

sf::Color tPoint::get_tPointColor() {
    return convex.getFillColor();
}

void tPoint::linearMove(sf::Vector2i win, float _elSecs) {
    sf::Vector2f pos = convex.getPosition();
    convex.setPosition(pos.x + (speed.x * _elSecs), pos.y + (speed.y * _elSecs));

    sf::FloatRect boundingBox = convex.getGlobalBounds();
    pos = convex.getPosition();
    if (boundingBox.left + boundingBox.width > win.x || boundingBox.left < 0) {
        convex.setPosition(pos.x - (speed.x * _elSecs), pos.y);
        speed.x *= -1;                                                                     // перемещение в линейном направлении
    }
    if (boundingBox.top + boundingBox.height > win.y || boundingBox.top < 0) {
        convex.setPosition(pos.x, pos.y - (speed.y * _elSecs));
        speed.y *= -1;
    }
}

void tPoint::randomMove(sf::Vector2i win, float _elSecs) {
    int c = 100;
    int rc = URNG(0, 99);

    if (rc < 5) c = URNG(0, 99);

    if (c < 25) {
        speed.x += 1;
        speed.y += 1;
    } else if (c < 50) {
        speed.x += 1;
        speed.y -= 1;
    } else if (c < 75) {                                                               // перемещение в случайном направлении
        speed.x -= 1;
        speed.y += 1;
    } else if (c < 100) {
        speed.x -= 1;
        speed.y -= 1;
    }

    linearMove(win, _elSecs);
}