#include "quich_sort.h"

namespace {

/// @brief Quick Sort Algorithm
/// @param arr The current array
/// @param low Left index of the array
/// @param high Right index of the array
void QuickSort(std::vector<int>& data, int low, int high,
               std::function<bool(int, int)>& comparator,
               std::function<void(const std::vector<int>&)>& visualizer) {
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(data, low, high, comparator, visualizer);

        // Recursion calls for smaller elements and greater or equals elements
        QuickSort(data, low, pi - 1, comparator, visualizer);
        QuickSort(data, pi + 1, high, comparator, visualizer);
    }
}

/// @brief Partition the array
/// @param data The current data
/// @param low Left index of the array
/// @param high Right index of the array
/// @return Pivot index (pivot's position)
int partition(std::vector<int>& data, int low, int high,
              std::function<bool(int, int)>& comparator,
              std::function<void(const std::vector<int>&)>& visualizer) {
    // Choose the pivot
    int pivot = data[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int iter = low - 1;

    // Traverse arr[low..high] and move all smaller elements on left side.
    // Elements from low to iter are smaller after every iteration
    for (int jter = low; jter <= high - 1; jter++) {
        if (comparator(data[jter], pivot)) {
            iter++;
            std::swap(data[iter], data[jter]);
            if (visualizer) visualizer(data);
        }
    }

    // Move pivot after smaller elements and return its position
    std::swap(data[iter + 1], data[high]);
    if (visualizer) visualizer(data);

    return (iter + 1);
}

}  // namespace

void sorting::quick_sort::sort(
    std::vector<int>& data, std::function<bool(int, int)> comparator,
    std::function<void(const std::vector<int>&)>& visualizer) {
    int n = data.size() - 1;
    QuickSort(data, 0, n, comparator, visualizer);
}
