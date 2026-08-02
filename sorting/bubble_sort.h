#pragma once

#include <functional>
#include <vector>

namespace sorting {

void BubbleSort(std::vector<int>& data,
                std::function<bool(int, int)> comparator = std::less<int>{},
                std::function<void(const std::vector<int>&)> visualizer);

};  // namespace sorting