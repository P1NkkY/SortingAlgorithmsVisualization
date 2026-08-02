#include "bubble_sort.h"

void sorting::bubble_sort::sort(
    std::vector<int>& data, std::function<bool(int, int)> comparator,
    std::function<void(const std::vector<int>&)>& visualizer) {
    for (int iter = 0; iter < data.size() - 1; iter++) {
        for (int jter = 0; jter < data.size() - iter - 1; jter++) {
            if (comparator(data[jter + 1], data[jter])) {
                std::swap(data[jter], data[jter + 1]);
                if (visualizer) {
                    visualizer(data);
                }
            }
        }
    }
}