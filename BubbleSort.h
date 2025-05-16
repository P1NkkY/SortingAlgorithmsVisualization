#pragma once

#include "ISorting.h"

class BubbleSort : public ISorting {
  public:
    explicit BubbleSort(std::vector<int> &data);

    void Calculate();

  private:
    bool complete = false;
};