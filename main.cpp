#include <iostream>
#include <numeric>
#include <random>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "SortingVisualization.h"

std::vector<int> createArray() {
    std::vector<int> res(50);
    std::iota(res.begin(), res.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(res.begin(), res.end(), g);

    return res;
}

int main() {
    std::vector<int> arr = createArray();

    std::unique_ptr<BubbleSort> bubbleSort = std::make_unique<BubbleSort>(arr);

    std::unique_ptr<SortingVisualization> visualizer =
        std::make_unique<SortingVisualization>(*bubbleSort.get());
    visualizer.get()->start();

    return 0;
}
