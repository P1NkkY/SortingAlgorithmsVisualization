#include "VisualDataStorage.h"

#define SIZE_INCRENENT 2
#define SPACE_BETWEEN 1

VisualDataStorage::VisualDataStorage() {}

VisualDataStorage::~VisualDataStorage() {
    std::cout << "~VisualDataStorage" << std::endl;
}

void VisualDataStorage::init(const std::vector<int> &arr) {
    barsArrSize = arr.size();
    bars.resize(barsArrSize);

    // Set the position and default size for bars
    barWidth = (WINDOW_WIDTH - SPACE_BETWEEN * barsArrSize) / barsArrSize;
    for (int iter = 0; iter < barsArrSize; iter++) {
        bars[iter].setPosition(sf::Vector2f(iter * barWidth + iter, 0));
        bars[iter].setSize(sf::Vector2f(barWidth, arr[iter] * SIZE_INCRENENT));
    }
}

void VisualDataStorage::updateBars(const std::vector<int> &arr) {
    for (int iter = 0; iter < barsArrSize; iter++) {
        bars[iter].setSize(sf::Vector2f(barWidth, arr[iter] * SIZE_INCRENENT));
    }
}