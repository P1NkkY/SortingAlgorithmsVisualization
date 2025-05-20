#pragma once
#include <iostream>
#include <mutex>
#include <vector>

#include "boost/signals2.hpp"

class ISortingAlgorithm {
  public:
    explicit ISortingAlgorithm(std::vector<int> &arr);

    virtual ~ISortingAlgorithm();

    // Returns the name of the algorithm
    virtual std::string getName() const = 0;

    std::vector<int> getArray() const;

    // Check whether the sorting algorithm is running
    bool isRunning() const;

    // Start sorting algorithm
    void start();

    // Stop sorting algorithm
    void stop();

    // Signal to update array visualization
    boost::signals2::signal<void(const std::vector<int> &)> updateVisualization;

  private:
    // Basic sorting method
    virtual void sort() = 0;

  protected:
    std::vector<int> m_arr;   // Array of elements
    int m_size;               // Array size
    bool m_isRunning = false; // Indicates whether the algorithm is running
    std::mutex m_locker;
};