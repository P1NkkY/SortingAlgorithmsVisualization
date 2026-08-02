#include "insertion_sort.h"

void sorting::InsertionSort(
    std::vector<int>& data, std::function<bool(int, int)> comparator,
    std::function<void(const std::vector<int>&)> visualizer) {
    for (int iter = 1; iter < data.size(); iter++) {
        int current = data[iter];
        int jter = iter;

        while (jter > 0 && comparator(current, data[jter - 1])) {
            data[jter] = data[jter - 1];
            jter--;
            if (visualizer) visualizer(data);
        }
        if (jter != iter) {
            data[jter] = current;
            if (visualizer) visualizer(data);
        }
    }
}