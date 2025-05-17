#include "SFML/Graphics.hpp"
#include "boost/signals2.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "Visualization.h"

std::vector<int> CreateArray() {
    std::vector<int> res(101); // вектор на 101 элемент (0-100)

    // Заполняем последовательными числами
    std::iota(res.begin(), res.end(), 0);

    // Перемешиваем
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(res.begin(), res.end(), g);

    return res;
}

int main() {

    std::vector<int> vec = CreateArray();

    Visualization vis(WINDOW_WIDTH, WINDOW_HEIGHT, vec.size(), vec);
    vis.Start();

    BubbleSort *sort = new BubbleSort(vec);
    InsertionSort *ins = new InsertionSort(vec);
    SelectionSort *sel = new SelectionSort(vec);
    QuickSort *q = new QuickSort(vec);
    MergeSort m(vec);
    m.signalUPD.connect(
        boost::bind(&Visualization::Update, &vis, boost::placeholders::_1));
    m.Calculate();

    // std::vector<sf::RectangleShape> rectangles;
    // rectangles.resize(vec.size());
    // int width = 5;

    // for (int iter = 0; iter < vec.size(); iter++) {
    //     sf::RectangleShape rect(sf::Vector2f(width, vec[iter] * 3));
    //     rect.setPosition(sf::Vector2f(iter * 5 + iter, 0));
    //     rectangles[iter] = rect;
    // }

    // // create the window
    // sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // int iter = 0;
    // bool start = true;
    // // run the program as long as the window is open
    // while (window.isOpen()) {
    //     // check all the window's events that were triggered since the last
    //     // iteration of the loop
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         // "close requested" event: we close the window
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     // clear the window with black color
    //     window.clear(sf::Color::Black);

    //     if (start) {
    //         start = false;
    //         for (auto rect : rectangles) {
    //             window.draw(rect);
    //         }
    //         continue;
    //     }

    //     if (iter < vec.size() - 1) {
    //         if (vec[iter] < vec[iter + 1]) {
    //             iter++;
    //         } else {
    //             std::swap(vec[iter], vec[iter + 1]);
    //             iter = 0;
    //         }
    //     }

    //     for (int jter = 0; jter < vec.size(); jter++) {
    //         sf::RectangleShape rect(sf::Vector2f(width, vec[jter] * 3));
    //         rect.setPosition(sf::Vector2f(jter * 5 + jter, 0));
    //         rectangles[jter] = rect;
    //         if (iter == jter)
    //             rectangles[jter].setFillColor(sf::Color::Red);
    //     }

    //     for (auto rect : rectangles) {
    //         window.draw(rect);
    //     }

    //     // end the current frame
    //     window.display();

    //     // sf::sleep(sf::milliseconds(3));
    // }

    // std::this_thread::sleep_for(std::chrono::seconds(20));

    return 0;
}
