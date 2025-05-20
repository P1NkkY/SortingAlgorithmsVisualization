/* Merge Sort Algorithm.
   Divide:  Divide the list or array recursively into two halves until it can no
 more be divided.
   Conquer:  Each subarray is sorted individually using the merge
 sort algorithm.
   Merge:  The sorted subarrays are merged back together in sorted
 order. The process continues until all elements from both subarrays have been
 merged.

   Time Complexity.
 - Best Case: O(n log n), When the array is already sorted or nearly sorted.
 - Average Case: O(n log n), When the array is randomly ordered.
 - Worst Case: O(n log n), When the array is sorted in reverse order.

   Space Complexity.
   Auxiliary Space: O(n), Additional space is required for the temporary array
used during merging.
*/
#pragma once

#include "ISortingAlgorithm.h"

class MergeSort : public ISortingAlgorithm {
  public:
    explicit MergeSort(std::vector<int> &arr);

    ~MergeSort();

    std::string getName() const;

  private:
    void sort();

    /// @brief Merge sort algorithm
    /// @param arr The current array
    /// @param left Left index of the array
    /// @param right Right index of the array
    void mergeSort(std::vector<int> &arr, int left, int right);

    /// @brief Merges two subarrays. arr[left..mid] and arr[mid+1..right]
    /// @param arr The current array
    /// @param left Left index of the array
    /// @param mid Middle index of the array
    /// @param right Right middle of the array
    void merge(std::vector<int> &arr, int left, int mid, int right);
};