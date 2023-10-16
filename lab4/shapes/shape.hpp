#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics/ConvexShape.hpp>

class Shape: public sf::ConvexShape {
private:
    sf::Vector2f speed;

public:
    Shape();

    void setSpeed(sf::Vector2f _speed);
    void setSpeed(float _x, float _y);
    sf::Vector2f getSpeed(void);

    void move(sf::Vector2i win, sf::Vector2f offset);
    void move(int winX, int winY, float offsetX, float offsetY);
    void move(sf::Vector2i win, float offsetX, float offsetY);
    void move(int winX, int winY, sf::Vector2f offset);

    void rotate(float ang);
};

#endif // SHAPE_HPP