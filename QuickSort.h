#pragma once

#include "ISorting.h"

class QuickSort : public ISorting {
  public:
    explicit QuickSort(std::vector<int> &data);

    void Calculate();

  private:
    int partition(std::vector<int> &arr, int low, int high);

    void quickSort(std::vector<int> &arr, int low, int high);

  private:
    bool complete;
};