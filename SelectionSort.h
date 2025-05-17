#pragma once

#include "ISorting.h"

class SelectionSort : public ISorting {
  public:
    explicit SelectionSort(std::vector<int> &data);

    void Calculate();

  private:
    bool complete;
};