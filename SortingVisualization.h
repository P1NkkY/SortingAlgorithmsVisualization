#pragma once

#include "ISortingAlgorithm.h"
#include "VisualDataStorage.h"
#include <thread>

class SortingVisualization : public VisualDataStorage {
  public:
    explicit SortingVisualization(ISortingAlgorithm &sorter);

    ~SortingVisualization();

    /// @brief Running sorting algorithm with visualization
    void start();

    /// @brief SLOT to update visualization of bars
    /// @param arr The current array
    void updateWindow(const std::vector<int> &arr);

  private:
    /// @brief Clear the window with black color
    void clear();

    /// @brief Display the current frame
    void display();

    /// @brief Draw the current array bars
    void draw();

  private:
    sf::RenderWindow *m_window;
    ISortingAlgorithm &m_sorter;
    std::thread m_th;
};