/* Insertion Sort Algorithm.
   We start with the second element of the array as the first element is
 assumed to be sorted. Compare the second element with the first element if the
 second element is smaller then swap them. Move to the third element, compare
 it with the first two elements, and put it in its correct position Repeat until
 the entire array is sorted.

   Time Complexity.
 - Best case: O(n), If the list is already sorted, where n is the number of
 elements in the list.
 - Average case: O(n²), If the list is randomly ordered.
 - Worst case: O(n²), If the list is in reverse order.

   Space Complexity.
   Auxiliary Space: O(1), Insertion sort requires O(1) additional space, making
 it a space-efficient sorting algorithm.
 */

#pragma once

#include "ISortingAlgorithm.h"

class InsertionSort : public ISortingAlgorithm {
  public:
    explicit InsertionSort(std::vector<int> &arr);

    ~InsertionSort();

    std::string getName() const;

  private:
    void sort();
};