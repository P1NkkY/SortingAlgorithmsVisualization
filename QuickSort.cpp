#include "QuickSort.h"

QuickSort::QuickSort(std::vector<int> &arr) : ISortingAlgorithm(arr) {}

QuickSort::~QuickSort() { std::cout << "~QuickSort" << std::endl; }

std::string QuickSort::getName() const { return "Quick Sort"; }

void QuickSort::sort() {
    quickSort(m_arr, 0, m_size - 1);
    stop();
}

void QuickSort::quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<int> &arr, int low, int high) {
    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int iter = low - 1;

    // Traverse arr[low..high] and move all smaller elements on left side.
    // Elements from low to iter are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            iter++;
            std::swap(arr[iter], arr[j]);
            updateVisualization(arr);
        }
    }

    // Move pivot after smaller elements and return its position
    std::swap(arr[iter + 1], arr[high]);
    updateVisualization(arr);

    return (iter + 1);
}
