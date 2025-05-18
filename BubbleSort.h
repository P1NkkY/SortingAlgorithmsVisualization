/* Bubble Sort Algorithm.
   We sort the array using multiple passes. After the first pass, the maximum
element goes to end (its correct position). Same way, after second pass, the
second largest element goes to second last position and so on.
    In every pass, we process only those elements that have already not moved to
correct position. After k passes, the largest k elements must have been moved to
the last k positions.
    In a pass, we consider remaining elements and compare all adjacent and swap
if larger element is before a smaller element. If we keep doing this, we get the
largest (among the remaining elements) at its correct position.

Time Complexity: O(n²)

Space Complexity: O(1)
*/

#pragma once

#include "ISortingAlgorithm.h"

class BubbleSort : public ISortingAlgorithm {
  public:
    explicit BubbleSort(std::vector<int> &arr);

    ~BubbleSort();

    void sort();

    std::string getName() const;
};