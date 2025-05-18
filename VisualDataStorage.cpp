#include "VisualDataStorage.h"

VisualDataStorage::VisualDataStorage() {
    std::cout << "VisualDataStorage" << std::endl;
}

VisualDataStorage::~VisualDataStorage() {
    std::cout << "~VisualDataStorage" << std::endl;
}

void VisualDataStorage::initData(int size) {
    barsArrSize = size;
    bars.resize(barsArrSize);

    barWidth = WINDOW_WIDTH / barsArrSize;

    // Расставляем позицию
    for (int iter = 0; iter < barsArrSize; iter++) {
        bars[iter].setPosition(sf::Vector2f(iter * barWidth + iter, 0));
    }
}

void VisualDataStorage::updateBars(const std::vector<int> &arr) {
    for (int iter = 0; iter < barsArrSize; iter++) {
        bars[iter].setSize(sf::Vector2f(barWidth, arr[iter] * 2));
    }
}