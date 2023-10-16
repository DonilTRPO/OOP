#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape {
private:
    float side;

    void updatePoints();

    void setPointCount();       // don't allow user to break PointCount
    void setPoint();            // don't allow user to break points

public:
    Triangle(float _side);
    Triangle();

    void setSide(float _side);
    float getSide(void);
};

#endif // TRIANGLE_HPP