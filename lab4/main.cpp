#include "shapes/shapes.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

int main(void) {
    sf::Vector2i win(1920, 1080);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;                 // сглаживание x8

    sf::RenderWindow window(sf::VideoMode(win.x, win.y), "L4", sf::Style::Default, settings);
    window.setFramerateLimit(240);                  // FPS limit

    std::cout << "Window size: " << win.x << "x" << win.y << std::endl;

    sf::Clock clock;                                // для равномерного движения

    Point point;
    point.setPosition(10, 10);
    point.setFillColor(sf::Color::Green);
    point.setSpeed(100, 50);

    Circle circle(20);
    circle.setPosition(50, 50);
    circle.setFillColor(sf::Color::Yellow);
    circle.setSpeed(30, 30);

    Ellipse ellipse(50, 20);
    ellipse.setPosition(500, 500);
    ellipse.setFillColor(sf::Color::Magenta);
    ellipse.setSpeed(75, 200);

    Rectangle rectangle(60, 30);
    rectangle.setPosition(100, 100);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setSpeed(100, 20);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

    Line line(200, 5);
    line.setPosition(200, 10);
    line.setFillColor(sf::Color::Cyan);
    line.setSpeed(150, 120);
    line.setOrigin(line.getLength() / 2, line.getThickness() / 2);

    Triangle triangle(60);
    triangle.setPosition(66, 88);
    triangle.setFillColor(sf::Color(105, 141, 92));
    triangle.setSpeed(400, 15);
    triangle.setOrigin(triangle.getSide() / 2, triangle.getSide() / 2);

    Rhombus rhombus(200, 100);
    rhombus.setPosition(800, 100);
    rhombus.setFillColor(sf::Color(55, 99, 200));
    rhombus.setSpeed(140, 140);
    rhombus.setOrigin(rhombus.getSize().x / 2, rhombus.getSize().y / 2);

    float elapsedSecs = 0;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();  // закрыть окно
        }

        elapsedSecs = clock.restart().asSeconds();            // секунд прошло с пред. итерации

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            point.rotate(-1);
            circle.rotate(-1);
            ellipse.rotate(-1);
            rectangle.rotate(-1);
            line.rotate(-1);
            triangle.rotate(-1);
            rhombus.rotate(-1);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            point.rotate(1);
            circle.rotate(1);
            ellipse.rotate(1);
            rectangle.rotate(1);
            line.rotate(1);
            triangle.rotate(1);
            rhombus.rotate(1);
        }

        point.move(win, point.getSpeed() * elapsedSecs);
        circle.move(win, circle.getSpeed() * elapsedSecs);
        ellipse.move(win, ellipse.getSpeed() * elapsedSecs);
        rectangle.move(win, rectangle.getSpeed() * elapsedSecs);
        line.move(win, line.getSpeed() * elapsedSecs);
        triangle.move(win, triangle.getSpeed() * elapsedSecs);
        rhombus.move(win, rhombus.getSpeed() * elapsedSecs);

        window.clear(sf::Color::Black);

        window.draw(point);
        window.draw(circle);
        window.draw(ellipse);
        window.draw(rectangle);
        window.draw(line);
        window.draw(triangle);
        window.draw(rhombus);

        window.display();                                       // отображение кадра
    }

    return EXIT_SUCCESS;
}