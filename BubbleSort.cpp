#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<int> &data) : ISorting(data) {
    // connect signal - slot
}

void BubbleSort::Calculate() {
    int iter = 0;
    while (iter < m_size - 1) {
        if (iter < m_size - 1) {
            if (m_data[iter] < m_data[iter + 1]) {
                iter++;
            } else {
                std::swap(m_data[iter], m_data[iter + 1]);
                iter = 0;
            }
            // emit signal
        }
    }

    // emit signal complete
}
