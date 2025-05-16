#include "SFML/Graphics.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "BubbleSort.h"

int main() {

    std::vector<int> vec(101); // вектор на 101 элемент (0-100)
    std::vector<int> vec1;
    BubbleSort *sort = new BubbleSort(vec1);

    // Заполняем последовательными числами
    std::iota(vec.begin(), vec.end(), 0);

    // Перемешиваем
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);

    std::vector<sf::RectangleShape> rectangles;
    rectangles.resize(vec.size());
    int width = 5;

    for (int iter = 0; iter < vec.size(); iter++) {
        sf::RectangleShape rect(sf::Vector2f(width, vec[iter] * 3));
        rect.setPosition(sf::Vector2f(iter * 5 + iter, 0));
        rectangles[iter] = rect;
    }

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    int iter = 0;
    bool start = true;
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last
        // iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        if (start) {
            start = false;
            for (auto rect : rectangles) {
                window.draw(rect);
            }
            continue;
        }

        if (iter < vec.size() - 1) {
            if (vec[iter] < vec[iter + 1]) {
                iter++;
            } else {
                std::swap(vec[iter], vec[iter + 1]);
                iter = 0;
            }
        }

        for (int jter = 0; jter < vec.size(); jter++) {
            sf::RectangleShape rect(sf::Vector2f(width, vec[jter] * 3));
            rect.setPosition(sf::Vector2f(jter * 5 + jter, 0));
            rectangles[jter] = rect;
            if (iter == jter)
                rectangles[jter].setFillColor(sf::Color::Red);
        }

        for (auto rect : rectangles) {
            window.draw(rect);
        }

        // end the current frame
        window.display();

        // sf::sleep(sf::milliseconds(3));
    }

    return 0;
}
