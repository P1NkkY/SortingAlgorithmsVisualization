#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<int> &data) : ISorting(data) {
    // connect signal - slot
}

void InsertionSort::Calculate() {
    for (int iter = 1; iter < m_size; iter++) {
        int key = m_data[iter];
        int jter = iter - 1;

        while (jter >= 0 && m_data[jter] > key) {
            m_data[jter + 1] = m_data[jter];
            jter--;
        }
        m_data[jter + 1] = key;
        // emit signal
    }
    // emit signal complete
}