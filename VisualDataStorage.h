#pragma once
#include "SFML/Graphics.hpp"
#include "constants.h"
#include <iostream>

class VisualDataStorage {
  public:
    explicit VisualDataStorage();

    ~VisualDataStorage();

    void initData(int size);

    void updateBars(const std::vector<int> &arr);

  protected:
    std::vector<sf::RectangleShape> bars; // "Полоски" для отображения
    int barsArrSize = -1;                 // Кол-во "полосок"
    double barWidth;                      // Толщина "полосок"
};