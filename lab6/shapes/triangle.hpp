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

    void setOriginAtCenter() override;

    void move(sf::Vector2i win, sf::Vector2f offset) override;
    void move(int winX, int winY, float offsetX, float offsetY) override;
    void move(sf::Vector2i win, float offsetX, float offsetY) override;
    void move(int winX, int winY, sf::Vector2f offset) override;

    void rotate(float _ang) override;
};

#endif // TRIANGLE_HPP
