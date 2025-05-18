#include "MergeSort.h"

MergeSort::MergeSort(std::vector<int> &arr) : ISortingAlgorithm(arr) {}

MergeSort::~MergeSort() { std::cout << "~MergeSort" << std::endl; }

void MergeSort::sort() {
    mergeSort(m_arr, 0, m_size - 1);
    m_sorted = true;
}

std::string MergeSort::getName() const { return "Merge Sort"; }

void MergeSort::mergeSort(std::vector<int> &arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void MergeSort::merge(std::vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int iter = 0; iter < n1; iter++)
        L[iter] = arr[left + iter];
    for (int jter = 0; jter < n2; jter++)
        R[jter] = arr[mid + 1 + jter];

    int iter = 0, jter = 0;
    int kter = left;

    // Merge the temp vectors back into arr[left..right]
    while (iter < n1 && jter < n2) {
        if (L[iter] <= R[jter]) {
            arr[kter] = L[iter];
            iter++;
        } else {
            arr[kter] = R[jter];
            jter++;
        }
        kter++;
    }

    // Copy the remaining elements of L[], if there are any
    while (iter < n1) {
        arr[kter] = L[iter];
        iter++;
        kter++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (jter < n2) {
        arr[kter] = R[jter];
        jter++;
        kter++;
    }

    updateVisualization(arr);
}