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

    void move(sf::Vector2i win, sf::Vector2f offset) override;
    void move(int winX, int winY, float offsetX, float offsetY) override;
    void move(sf::Vector2i win, float offsetX, float offsetY) override;
    void move(int winX, int winY, sf::Vector2f offset) override;

    void rotate(float _ang) override;
};

#endif // POINT_HPP
