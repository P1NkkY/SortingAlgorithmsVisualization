#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<int> &arr) : ISortingAlgorithm(arr) {}

InsertionSort::~InsertionSort() { std::cout << "~InsertionSort" << std::endl; }

void InsertionSort::sort() {
    for (int iter = 1; iter < m_size; iter++) {
        int key = m_arr[iter];
        int jter = iter - 1;

        while (jter >= 0 && m_arr[jter] > key) {
            m_arr[jter + 1] = m_arr[jter];
            jter--;
            updateVisualization(m_arr);
        }
        m_arr[jter + 1] = key;
        updateVisualization(m_arr);
    }
    m_sorted = true;
}

std::string InsertionSort::getName() const { return "Insertion Sort"; }