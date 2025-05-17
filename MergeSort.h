#pragma once

#include "ISorting.h"
#include "boost/signals2/signal.hpp"

class MergeSort : public ISorting {
  public:
    explicit MergeSort(std::vector<int> &data);

    void Calculate();

    boost::signals2::signal<void(const std::vector<int> &)> signalUPD; // Signal

  private:
    void mergeSort(std::vector<int> &arr, int left, int right);

    void merge(std::vector<int> &arr, int left, int mid, int right);

  private:
    bool complete = false;
};