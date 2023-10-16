#ifndef LINE_HPP
#define LINE_HPP

#include "shape.hpp"

class Line : public Shape {
private:
    float length;
    float thickness;

    void updatePoints();

    void setPointCount();       // don't allow user to break PointCount
    void setPoint();            // don't allow user to break points

public:
    Line(float _length, float _thickness);
    Line(float _length);
    Line();

    void setLength(float _length);
    float getLength(void);

    void setThickness(float _thickness);
    float getThickness(void);
};

#endif // LINE_HPP