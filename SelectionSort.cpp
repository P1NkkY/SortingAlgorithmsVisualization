#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<int> &data) : ISorting(data) {
    // connect signal - slot
}

void SelectionSort::Calculate() {
    for (int iter = 0; iter < m_size - 1; iter++) {
        int min_index = iter;
        for (int jter = iter + 1; jter < m_size; jter++) {
            if (m_data[jter] < m_data[min_index]) {
                min_index = jter;
            }
        }
        std::swap(m_data[iter], m_data[min_index]);
    }
}
