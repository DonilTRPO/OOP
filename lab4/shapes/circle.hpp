#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape {
private:
    float radius;
    const int pointCount = 90;  // for drawing a smooth circle

    void updatePoints(void);

    void setPointCount();       // don't allow user to break PointCount
    void setPoint();            // don't allow user to break points

public:
    Circle(float _radius);
    Circle();

    void setRadius(float _radius);
    float getRadius(void);
};

#endif // CIRCLE_HPP