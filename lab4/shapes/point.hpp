#ifndef POINT_HPP
#define POINT_HPP

#include "circle.hpp"

class Point : public Circle {
private:
    void setRadius(float _r);   // don't allow user to change radius
    void setPointCount();       // don't allow user to break PointCount
    void setPoint();            // don't allow user to break points

public:
    Point();

    float getRadius(void);
};

#endif // POINT_HPP
