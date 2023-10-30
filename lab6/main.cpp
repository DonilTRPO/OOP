#include "shapes/shape.hpp"
#include "shapes/point.hpp"
#include "shapes/circle.hpp"
#include "shapes/ellipse.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/line.hpp"
#include "shapes/triangle.hpp"
#include "shapes/rhombus.hpp"

#include "URNG.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define MIN_SPEED 10
#define MAX_SPEED 200

#define MIN_RADIUS 10
#define MAX_RADIUS 30

#define MIN_WIDTH 40
#define MAX_WIDTH 100

int main(void) {
    sf::Vector2i win(1920, 1080);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;                 // сглаживание x8

    sf::RenderWindow window(sf::VideoMode(win.x, win.y), "L5", sf::Style::Default, settings);
    window.setFramerateLimit(240);                  // FPS limit

    std::cout << "Window size: " << win.x << "x" << win.y << std::endl;

    sf::Clock clock;                                // для равномерного движения

    Point* point = new Point();
    Circle* circle = new Circle();
    Ellipse* ellipse = new Ellipse();
    Line* line = new Line();
    Triangle* triangle = new Triangle();
    Rhombus* rhombus = new Rhombus();
    Rectangle* rectangle = new Rectangle();

    std::vector<Shape*> shapes;

    shapes.push_back(point);
    shapes.push_back(circle);
    shapes.push_back(ellipse);
    shapes.push_back(line);
    shapes.push_back(triangle);
    shapes.push_back(rhombus);
    shapes.push_back(rectangle);

    circle->setRadius(URNG(MIN_RADIUS, MAX_RADIUS));
    ellipse->setRadius(URNG(MIN_RADIUS * 4, MAX_RADIUS * 3), URNG(MIN_RADIUS * 4, MAX_RADIUS * 3));
    line->setSize(URNG(MIN_WIDTH * 3, MAX_WIDTH * 3), URNG(2, 6));
    triangle->setSide(URNG(MIN_WIDTH, MAX_WIDTH));
    rhombus->setSize(URNG(MIN_WIDTH * 2, MAX_WIDTH * 2), URNG(MIN_WIDTH * 2, MAX_WIDTH * 2));
    rectangle->setSize(URNG(MIN_WIDTH * 2, MAX_WIDTH * 2), URNG(MIN_WIDTH * 2 / 1.5, MAX_WIDTH * 2 / 1.5));

    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->setPosition(URNG(200, win.x - 200), URNG(200, win.y - 200));
        shapes[i]->setFillColor(sf::Color(URNG(0, 255), URNG(0, 255), URNG(0, 255)));
        shapes[i]->setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));
        shapes[i]->setOriginAtCenter();
    }

    float elapsedSecs = 0;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();  // закрыть окно
        }

        elapsedSecs = clock.restart().asSeconds();            // секунд прошло с пред. итерации

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            for (int i = 0; i < shapes.size(); i++) shapes[i]->rotate(-1);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            for (int i = 0; i < shapes.size(); i++) shapes[i]->rotate(1);
        }

        for (int i = 0; i < shapes.size(); i++) shapes[i]->move(win, shapes[i]->getSpeed() * elapsedSecs);

        window.clear(sf::Color::Black);

        for (int i = 0; i < shapes.size(); i++) window.draw(*shapes[i]);

        window.display();                                     // отображение кадра
    }

    for (int i = 0; i < shapes.size(); i++) delete shapes[i];

    return 0;
}
