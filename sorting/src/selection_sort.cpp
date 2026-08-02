#include "selection_sort.h"

void sorting::selection_sort::sort(
    std::vector<int>& data, std::function<bool(int, int)> comparator,
    std::function<void(const std::vector<int>&)>& visualizer) {
    for (int iter = 0; iter < data.size() - 1; iter++) {
        int min_index = iter;
        for (int jter = iter + 1; jter < data.size(); jter++) {
            if (comparator(data[jter], data[min_index])) {
                min_index = jter;
            }
        }
        if (min_index != iter) {
            std::swap(data[iter], data[min_index]);
            if (visualizer) visualizer(data);
        }
    }
}