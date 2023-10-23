#include "shapes/shapes.hpp"
#include "URNG.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define SHAPES_COUNT 1

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

    Point point[SHAPES_COUNT];
    Circle circle[SHAPES_COUNT];
    Ellipse ellipse[SHAPES_COUNT];
    Line line[SHAPES_COUNT];
    Triangle triangle[SHAPES_COUNT];
    Rhombus rhombus[SHAPES_COUNT];
    Rectangle rectangle[SHAPES_COUNT];

    sf::Texture t;

    for (int i = 0; i < SHAPES_COUNT; i++) {
        point[i].setPosition(URNG(10, win.x - 10), URNG(10, win.y - 10));
        point[i].setFillColor(sf::Color(URNG(0, 255), URNG(0, 255), URNG(0, 255)));
        point[i].setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));

        circle[i].setPosition(URNG(MAX_RADIUS + 10, win.x - MAX_RADIUS - 10), URNG(MAX_RADIUS + 10, win.y - MAX_RADIUS - 10));
        circle[i].setFillColor(sf::Color(URNG(0, 255), URNG(0, 255), URNG(0, 255)));
        circle[i].setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));
        circle[i].setRadius(URNG(MIN_RADIUS, MAX_RADIUS));

        ellipse[i].setPosition(URNG(MAX_RADIUS, win.x - MAX_RADIUS), URNG(MAX_RADIUS, win.y - MAX_RADIUS));
        ellipse[i].setFillColor(sf::Color(URNG(0, 255), URNG(0, 255), URNG(0, 255)));
        ellipse[i].setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));
        ellipse[i].setRadius(URNG(MIN_RADIUS * 4, MAX_RADIUS * 3), URNG(MIN_RADIUS * 4, MAX_RADIUS * 3));

        line[i].setPosition(URNG(MAX_WIDTH, win.x - MAX_WIDTH), URNG(MAX_WIDTH, win.y - MAX_WIDTH));
        line[i].setFillColor(sf::Color(URNG(0, 255), URNG(0, 255), URNG(0, 255)));
        line[i].setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));
        line[i].setLength(URNG(MIN_WIDTH * 3, MAX_WIDTH * 3));
        line[i].setThickness(URNG(2, 6));
        line[i].setOrigin(line[i].getLength() / 2, line[i].getThickness() / 2);

        triangle[i].setPosition(URNG(MAX_WIDTH, win.x - MAX_WIDTH), URNG(MAX_WIDTH, win.y - MAX_WIDTH));
        triangle[i].setFillColor(sf::Color(URNG(0, 255), URNG(0, 255), URNG(0, 255)));
        triangle[i].setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));
        triangle[i].setSide(URNG(MIN_WIDTH, MAX_WIDTH));
        triangle[i].setOrigin(triangle[i].getSide() / 2, triangle[i].getSide() / 2);

        rhombus[i].setPosition(URNG(MAX_WIDTH, win.x - MAX_WIDTH), URNG(MAX_WIDTH, win.y - MAX_WIDTH));
        rhombus[i].setFillColor(sf::Color(URNG(0, 255), URNG(0, 255), URNG(0, 255)));
        rhombus[i].setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));
        rhombus[i].setSize(URNG(MIN_WIDTH * 2, MAX_WIDTH * 2), URNG(MIN_WIDTH * 2, MAX_WIDTH * 2));
        rhombus[i].setOrigin(rhombus[i].getSize().x / 2, rhombus[i].getSize().y / 2);

        rectangle[i].setPosition(URNG(MAX_WIDTH, win.x - MAX_WIDTH), URNG(MAX_WIDTH, win.y - MAX_WIDTH));
        rectangle[i].setFillColor(sf::Color::White);
        rectangle[i].setOutlineThickness(1.5);
        rectangle[i].setOutlineColor(sf::Color::White);
        rectangle[i].setSpeed(URNG(MIN_SPEED, MAX_SPEED), URNG(MIN_SPEED, MAX_SPEED));
        rectangle[i].setSize(URNG(MIN_WIDTH * 2, MAX_WIDTH * 2), URNG(MIN_WIDTH * 2 / 1.5, MAX_WIDTH * 2 / 1.5));
        rectangle[i].setOrigin(rectangle[i].getSize().x / 2, rectangle[i].getSize().y / 2);
        rectangle[i].setTexture(&t);
    }

    float elapsedSecs = 0;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();  // закрыть окно
        }

        elapsedSecs = clock.restart().asSeconds();            // секунд прошло с пред. итерации

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            for (int i = 0; i < SHAPES_COUNT; i++) {
                point[i].rotate(-1);
                circle[i].rotate(-1);
                ellipse[i].rotate(-1);
                rectangle[i].rotate(-1);
                line[i].rotate(-1);
                triangle[i].rotate(-1);
                rhombus[i].rotate(-1);
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            for (int i = 0; i < SHAPES_COUNT; i++) {
                point[i].rotate(1);
                circle[i].rotate(1);
                ellipse[i].rotate(1);
                rectangle[i].rotate(1);
                line[i].rotate(1);
                triangle[i].rotate(1);
                rhombus[i].rotate(1);
            }
        }

        for (int i = 0; i < SHAPES_COUNT; i++) {
            point[i].move(win, point[i].getSpeed() * elapsedSecs);
            circle[i].move(win, circle[i].getSpeed() * elapsedSecs);
            ellipse[i].move(win, ellipse[i].getSpeed() * elapsedSecs);
            line[i].move(win, line[i].getSpeed() * elapsedSecs);
            triangle[i].move(win, triangle[i].getSpeed() * elapsedSecs);
            rhombus[i].move(win, rhombus[i].getSpeed() * elapsedSecs);
            rectangle[i].move(win, rectangle[i].getSpeed() * elapsedSecs);
        }

        window.clear(sf::Color::Black);

        for (int i = 0; i < SHAPES_COUNT; i++) {
            window.draw(point[i]);
            window.draw(circle[i]);
            window.draw(ellipse[i]);
            window.draw(line[i]);
            window.draw(triangle[i]);
            window.draw(rhombus[i]);
            window.draw(rectangle[i]);
        }

        window.display();                                       // отображение кадра
    }

    return EXIT_SUCCESS;
}