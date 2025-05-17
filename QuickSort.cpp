#include "QuickSort.h"

QuickSort::QuickSort(std::vector<int> &data) : ISorting(data) {
    // connect signal - slot
}

void QuickSort::Calculate() {
    quickSort(m_data, 0, m_size - 1);
    std::cout << " Hllo";
}

int QuickSort::partition(std::vector<int> &arr, int low, int high) {

    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Move pivot after smaller elements and
    // return its position
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// The QuickSort function implementation
void QuickSort::quickSort(std::vector<int> &arr, int low, int high) {

    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}