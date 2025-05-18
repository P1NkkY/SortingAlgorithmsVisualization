#pragma once
#include <iostream>
#include <vector>

#include "boost/signals2.hpp"

class ISortingAlgorithm {
  public:
    explicit ISortingAlgorithm(std::vector<int> &arr);

    virtual ~ISortingAlgorithm();

    // Basic sorting method
    virtual void sort() = 0;

    // Returns the name of the algorithm
    virtual std::string getName() const = 0;

    // Returns the current array of elements
    std::vector<int> getCurrentState() const;

    // Signal to update array visualization
    boost::signals2::signal<void(const std::vector<int> &)> updateVisualization;

  protected:
    std::vector<int> m_arr; // Array of elements
    int m_size;             // Array size
    bool m_sorted = false;  // Indicates whether the array sorting has finished
};