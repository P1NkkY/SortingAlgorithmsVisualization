/* Quick Sort Algorithm.
   Choose a Pivot: Select an element from the array as the pivot. The choice of
pivot can vary (e.g., first element, last element, random element, or median).
   Partition the Array: Rearrange the array around the pivot. After
partitioning, all elements smaller than the pivot will be on its left, and all
elements greater than the pivot will be on its right. The pivot is then in its
correct position, and we obtain the index of the pivot.
   Recursively Call: Recursively apply the same process to the two partitioned
sub-arrays (left and right of the pivot).
   Base Case: The recursion stops when there is only one element left in the
sub-array, as a single element is already sorted.

   Time Complexity.
 - Best Case: O(n log n), Occurs when the pivot element divides the array into
two equal halves.
 - Average Case: O(n log n), On average, the pivot divides the
array into two parts, but not necessarily equal.
 - Worst Case: O(n²), Occurs when the smallest or largest element is always
chosen as the pivot (e.g., sorted arrays).

   Space Complexity.
   Auxiliary Space: O(n), due to recursive call stack
*/

#pragma once

#include "ISortingAlgorithm.h"

class QuickSort : public ISortingAlgorithm {
  public:
    explicit QuickSort(std::vector<int> &arr);

    ~QuickSort();

    void sort();

    std::string getName() const;

  private:
    /// @brief Quick Sort Algorithm
    /// @param arr The current array
    /// @param low Left index of the array
    /// @param high Right index of the array
    void quickSort(std::vector<int> &arr, int low, int high);

    /// @brief Partition the array
    /// @param arr The current array
    /// @param low Left index of the array
    /// @param high Right index of the array
    /// @return Pivot index (pivot's position)
    int partition(std::vector<int> &arr, int low, int high);
};