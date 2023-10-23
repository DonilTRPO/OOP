#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

class Ellipse : public Shape {
private:
    sf::Vector2f radius;
    const int pointCount = 90;  // for drawing a smooth ellipse

    void updatePoints(void);

    void setPointCount();       // don't allow user to break PointCount
    void setPoint();            // don't allow user to break points

public:
    Ellipse(sf::Vector2f _radius);
    Ellipse(float _radiusX, float _radiusY);
    Ellipse();

    void setRadius(sf::Vector2f _radius);
    void setRadius(float _radiusX, float _radiusY);
    sf::Vector2f getRadius(void);

    void move(sf::Vector2i win, sf::Vector2f offset) override;
    void move(int winX, int winY, float offsetX, float offsetY) override;
    void move(sf::Vector2i win, float offsetX, float offsetY) override;
    void move(int winX, int winY, sf::Vector2f offset) override;

    void rotate(float _ang) override;
};

#endif // ELLIPSE_HPP
