#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include "shape.hpp"

class Rhombus : public Shape {
private:
    sf::Vector2f size;

    void updatePoints();

    void setPointCount();       // don't allow user to break PointCount
    void setPoint();            // don't allow user to break points

public:
    Rhombus(sf::Vector2f _size);
    Rhombus(float _w, float _h);
    Rhombus();

    void setSize(sf::Vector2f _size);
    void setSize(float _w, float _h);
    sf::Vector2f getSize(void);
};

#endif // RHOMBUS_HPP