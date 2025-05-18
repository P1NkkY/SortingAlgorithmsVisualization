#include "VisualDataStorage.h"

#define SIZE_INCRENENT 2

VisualDataStorage::VisualDataStorage() {}

VisualDataStorage::~VisualDataStorage() {
    std::cout << "~VisualDataStorage" << std::endl;
}

void VisualDataStorage::initData(int size) {
    barsArrSize = size;
    bars.resize(barsArrSize);

    barWidth = WINDOW_WIDTH / (barsArrSize + 1);

    // Set the position for bars
    for (int iter = 0; iter < barsArrSize; iter++) {
        bars[iter].setPosition(sf::Vector2f(iter * barWidth + iter, 0));
    }
}

void VisualDataStorage::updateBars(const std::vector<int> &arr) {
    for (int iter = 0; iter < barsArrSize; iter++) {
        bars[iter].setSize(sf::Vector2f(barWidth, arr[iter] * SIZE_INCRENENT));
    }
}