#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape {
private:
    sf::Vector2f size;

    void updatePoints();

    void setPointCount();       // don't allow user to break PointCount
    void setPoint();            // don't allow user to break points

public:
    Rectangle(sf::Vector2f _size);
    Rectangle(float _w, float _h);
    Rectangle();

    void setSize(sf::Vector2f _size);
    void setSize(float _w, float _h);
    sf::Vector2f getSize(void);
};

#endif // RECTANGLE_HPP