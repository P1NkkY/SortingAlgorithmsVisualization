#pragma once

#include "ISortingAlgorithm.h"
#include "VisualDataStorage.h"
#include <thread>

class SortingVisualization : public VisualDataStorage {
  public:
    explicit SortingVisualization(ISortingAlgorithm &sorter);

    ~SortingVisualization();

    void Start();

    void Update(const std::vector<int> &arr);

  private:
    void Clear();

    void Display();

  private:
    sf::RenderWindow *m_window;
    ISortingAlgorithm &m_sorter;
    std::thread m_th;
};