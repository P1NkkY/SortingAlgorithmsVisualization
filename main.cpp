#include <iostream>
#include <numeric>
#include <random>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "SortingVisualization.h"

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
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = CreateArray();

    std::unique_ptr<BubbleSort> bubbleSort = std::make_unique<BubbleSort>(arr);
    std::unique_ptr<InsertionSort> insertionSort =
        std::make_unique<InsertionSort>(arr);
    std::unique_ptr<SelectionSort> selectionSort =
        std::make_unique<SelectionSort>(arr);
    std::unique_ptr<QuickSort> quickSort = std::make_unique<QuickSort>(arr);
    std::unique_ptr<MergeSort> mergeSort = std::make_unique<MergeSort>(arr);

    SortingVisualization vis(*quickSort.get());
    vis.Start();

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
