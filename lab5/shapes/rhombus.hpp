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

    void move(sf::Vector2i win, sf::Vector2f offset) override;
    void move(int winX, int winY, float offsetX, float offsetY) override;
    void move(sf::Vector2i win, float offsetX, float offsetY) override;
    void move(int winX, int winY, sf::Vector2f offset) override;

    void rotate(float _ang) override;
};

#endif // RHOMBUS_HPP
