#include <iostream>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "SortingVisualization.h"
#include "utils.h"

int main() {
    std::vector<int> arr = createArray();

    // If you want to use a different Sorting Algorithm, create pointer
    // to this object and pass it to the visualizer.
    std::unique_ptr<BubbleSort> bubbleSort = std::make_unique<BubbleSort>(arr);

    std::unique_ptr<SortingVisualization> visualizer =
        std::make_unique<SortingVisualization>(*bubbleSort.get());
    visualizer.get()->start();

    return 0;
}
