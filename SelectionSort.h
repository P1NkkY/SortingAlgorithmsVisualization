/* Selection Sort Algorithm
   First we find the smallest element and swap it with the first element. This
 way we get the smallest element at its correct position. Then we find the
 smallest among remaining elements (or second smallest) and swap it with the
 second element. We keep doing this until we get all elements moved to correct
 position.

   Time Complexity.
   O(n²), as there are two nested loops:
 - One loop to select an element of Array one by one = O(n)
 - Another loop to compare that element with every other Array element = O(n)
 - Therefore overall complexity = O(n) * O(n) = O(n*n) = O(n²)

   Space Complexity.
   Auxiliary Space: O(1) as the only extra memory used is for temporary
 variables.
 */

#pragma once

#include "ISortingAlgorithm.h"

class SelectionSort : public ISortingAlgorithm {
  public:
    explicit SelectionSort(std::vector<int> &arr);

    ~SelectionSort();

    void sort();

    std::string getName() const;
};