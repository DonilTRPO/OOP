#include "point.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

int main(void) {
    sf::Vector2i win(1920, 1080);
    std::cout << "Window size: " << win.x << "x" << win.y << std::endl;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;                 // сглаживание x8

    sf::RenderWindow window(sf::VideoMode(win.x, win.y), "L3", sf::Style::Default, settings);
    window.setFramerateLimit(240);                  // FPS limit

    sf::Clock clock;                                // для равномерного движения

    const int pCount = 100;                         // количество точек
    tPoint* points = new tPoint[pCount];            // массив точек

    const int speedLimit = 400;                     // макс. скорость точки
    int r = 5;                                      // радиус точки
    for (int p = 0; p < pCount; p++) {
        points[p].set_tPointRadius(r);
        points[p].set_tPointPosition(rand() % (win.x - r * 2), rand() % (win.y - r * 2));
        points[p].set_tPointColor(rand() % 256, rand() % 256, rand() % 256);
        points[p].set_tPointSpeed((rand() % speedLimit) + 1, (rand() % speedLimit) + 1);
    }

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();        // закрыть окно
        }

        float elapsedSecs = clock.restart().asSeconds();            // обновление состояния объекта между кадрами

        for (int p = 0; p < pCount; p++) {
            points[p].randomMove(win, elapsedSecs);                 // движение каждой точки
        }

        window.clear(sf::Color::Black);                             // черный фон
        for (int p = 0; p < pCount; p++)
            window.draw(points[p].get_tPointConvex());              // отрисовка каждой точки
        window.display();                                           // отображение кадра
    }

    delete[] points;
    return EXIT_SUCCESS;
}
