#include "point.hpp"

#define POINT_RADIUS 5

Point::Point() : Circle() {
    Circle::setRadius(POINT_RADIUS);
}

float Point::getRadius() {
    return POINT_RADIUS;
}
