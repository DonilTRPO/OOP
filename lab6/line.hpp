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
    Line(sf::Vector2f _size);
    Line(float _length);
    Line();

    void setSize(float _length, float _thickness);
    void setSize(sf::Vector2f _size);

    sf::Vector2f getSize();

    void setOriginAtCenter() override;

    void move(sf::Vector2i win, sf::Vector2f offset) override;
    void move(int winX, int winY, float offsetX, float offsetY) override;
    void move(sf::Vector2i win, float offsetX, float offsetY) override;
    void move(int winX, int winY, sf::Vector2f offset) override;

    void rotate(float _ang) override;
};

#endif // LINE_HPP
