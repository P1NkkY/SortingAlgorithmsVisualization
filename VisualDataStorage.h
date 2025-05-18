#pragma once
#include "SFML/Graphics.hpp"
#include "constants.h"
#include <iostream>

class VisualDataStorage {
  public:
    explicit VisualDataStorage();

    ~VisualDataStorage();

    /// @brief Initialize data
    /// @param size Size of the array
    void initData(int size);

    /// @brief Update visualization for current iteration of sorting
    /// @param arr The current array
    void updateBars(const std::vector<int> &arr);

  protected:
    std::vector<sf::RectangleShape> bars; // Bars to display
    int barsArrSize = -1;                 // Number of bars
    double barWidth;                      // Width of the bar
};