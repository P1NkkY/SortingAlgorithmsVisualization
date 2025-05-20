#pragma once
#include "SFML/Graphics.hpp"
#include "constants.h"
#include <iostream>

class VisualDataStorage {
  public:
    explicit VisualDataStorage();

    ~VisualDataStorage();

    /// @brief Initialize data
    /// @param arr The current array
    void init(const std::vector<int> &arr);

    /// @brief Update visualization for current iteration of sorting
    /// @param arr The current array
    void updateBars(const std::vector<int> &arr);

  protected:
    std::vector<sf::RectangleShape> bars; // Bars to display
    int barsArrSize = -1;                 // Number of bars
    double barWidth;                      // Width of the bar
};