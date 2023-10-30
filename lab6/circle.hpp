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

    void setOriginAtCenter() override;

    void move(sf::Vector2i win, sf::Vector2f offset) override;
    void move(int winX, int winY, float offsetX, float offsetY) override;
    void move(sf::Vector2i win, float offsetX, float offsetY) override;
    void move(int winX, int winY, sf::Vector2f offset) override;

    void rotate(float _ang) override;
};

#endif // CIRCLE_HPP
