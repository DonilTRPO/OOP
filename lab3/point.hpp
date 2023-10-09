#ifndef POINT_HPP
#define POINT_HPP

#include <SFML/Graphics/ConvexShape.hpp>

class tPoint {
private:
    sf::Vector2f speed;
    sf::ConvexShape convex;

    float radius;
    int dx, dy;
public:
    tPoint();

    void updateConvexPoints();
    sf::ConvexShape get_tPointConvex();

    void set_tPointRadius(float _radius);
    float get_tPointRadius();

    void set_tPointSpeed(float _x, float _y);
    sf::Vector2f get_tPointSpeed();

    void set_tPointPosition(float _x, float _y);
    sf::Vector2f get_tPointPosition();

    void set_tPointColor(int _r, int _g, int _b, int _alpha);
    void set_tPointColor(int _r, int _g, int _b);
    sf::Color get_tPointColor();

    void linearMove(sf::Vector2i win, float _elSecs);
    void randomMove(sf::Vector2i win, float _elSecs);
};

#endif // POINT_HPP
