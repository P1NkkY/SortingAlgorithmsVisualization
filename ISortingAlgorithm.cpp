#include "ISortingAlgorithm.h"

ISortingAlgorithm::ISortingAlgorithm(std::vector<int> &arr) : m_arr(arr) {
    m_size = m_arr.size();
}

ISortingAlgorithm::~ISortingAlgorithm() {
    std::cout << "~ISortingAlgorithm" << std::endl;
}

std::vector<int> ISortingAlgorithm::getCurrentState() const { return m_arr; }
