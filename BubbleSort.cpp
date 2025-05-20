#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<int> &arr) : ISortingAlgorithm(arr) {}

BubbleSort::~BubbleSort() { std::cout << "~BubbleSort" << std::endl; }

std::string BubbleSort::getName() const { return "Bubble Sort"; };

void BubbleSort::sort() {
    int iter = 0;
    while (iter < m_size - 1) {
        if (m_arr[iter] < m_arr[iter + 1]) {
            iter++;
        } else {
            std::swap(m_arr[iter], m_arr[iter + 1]);
            iter = 0;
            updateVisualization(m_arr);
        }
    }
    stop();
}