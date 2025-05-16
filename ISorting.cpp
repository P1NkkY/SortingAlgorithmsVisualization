#include "ISorting.h"

ISorting::ISorting(std::vector<int> &data) : m_data(data) {
    m_size = data.size();
}