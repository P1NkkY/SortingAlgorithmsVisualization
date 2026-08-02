#include "merge_sort.h"

namespace {

/// @brief Merges two subarrays. arr[left..mid] and arr[mid+1..right]
/// @param data The current array
/// @param left Left index of the array
/// @param mid Middle index of the array
/// @param right Right middle of the array
void merge(std::vector<int>& data, int left, int mid, int right,
           std::function<bool(int, int)>& comparator,
           std::function<void(const std::vector<int>&)>& visualizer) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::vector<int> L(n1), R(n2);
    // Copy data to temp vectors L[] and R[]
    for (int iter = 0; iter < n1; iter++) L[iter] = data[left + iter];
    for (int jter = 0; jter < n2; jter++) R[jter] = data[mid + 1 + jter];

    int iter = 0, jter = 0;
    int kter = left;

    // Merge the temp vectors back into arr[left..right]
    while (iter < n1 && jter < n2) {
        if (comparator(L[iter], R[jter])) {
            data[kter] = L[iter];
            iter++;
        } else {
            data[kter] = R[jter];
            jter++;
        }
        kter++;
        if (visualizer) visualizer(data);
    }

    // Copy the remaining elements of L[], if there are any
    while (iter < n1) {
        data[kter] = L[iter];
        iter++;
        kter++;
        if (visualizer) visualizer(data);
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (jter < n2) {
        data[kter] = R[jter];
        jter++;
        kter++;
        if (visualizer) visualizer(data);
    }
}

/// @brief Merge sort algorithm
/// @param data The current array
/// @param left Left index of the array
/// @param right Right index of the array
void MergeSort(std::vector<int>& data, int left, int right,
               std::function<bool(int, int)>& comparator,
               std::function<void(const std::vector<int>&)>& visualizer) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    MergeSort(data, left, mid, comparator, visualizer);
    MergeSort(data, mid + 1, right, comparator, visualizer);
    merge(data, left, mid, right, comparator, visualizer);
}

}  // namespace

void sorting::merge_sort::sort(
    std::vector<int>& data, std::function<bool(int, int)> comparator,
    std::function<void(const std::vector<int>&)>& visualizer) {
    MergeSort(data, 0, data.size() - 1, comparator, visualizer);
}
