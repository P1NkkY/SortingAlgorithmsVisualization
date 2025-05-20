#include "ISortingAlgorithm.h"

ISortingAlgorithm::ISortingAlgorithm(std::vector<int> &arr) : m_arr(arr) {
    m_size = m_arr.size();
}

ISortingAlgorithm::~ISortingAlgorithm() {
    std::cout << "~ISortingAlgorithm" << std::endl;
}

std::vector<int> ISortingAlgorithm::getArray() const { return m_arr; }

bool ISortingAlgorithm::isRunning() const { return m_isRunning; }

void ISortingAlgorithm::start() {
    std::unique_lock<std::mutex> locker(m_locker);
    if (!m_isRunning) {
        m_isRunning = true;
        std::thread th = std::thread([this]() { sort(); });
        th.detach();
    }
}

void ISortingAlgorithm::stop() {
    std::unique_lock<std::mutex> locker(m_locker);
    if (m_isRunning) {
        m_isRunning = false;
    }
}