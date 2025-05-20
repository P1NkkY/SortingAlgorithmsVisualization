#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<int> &arr) : ISortingAlgorithm(arr) {}

SelectionSort::~SelectionSort() { std::cout << "~SelectionSort" << std::endl; }

std::string SelectionSort::getName() const { return "Selection Sort"; }

void SelectionSort::sort() {
    for (int iter = 0; iter < m_size - 1; iter++) {
        int min_index = iter;
        for (int jter = iter + 1; jter < m_size; jter++) {
            if (m_arr[jter] < m_arr[min_index]) {
                min_index = jter;
            }
        }
        std::swap(m_arr[iter], m_arr[min_index]);
        updateVisualization(m_arr);
    }
    stop();
}