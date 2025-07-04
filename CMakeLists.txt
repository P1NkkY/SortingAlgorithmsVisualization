cmake_minimum_required(VERSION 3.28)
project(SortingAlgorithmsVisualization LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# Add your executable
add_executable(${PROJECT_NAME} 
    main.cpp
    ISortingAlgorithm.cpp
    BubbleSort.cpp
    InsertionSort.cpp
    SelectionSort.cpp
    QuickSort.cpp
    MergeSort.cpp
    SortingVisualization.cpp
    VisualDataStorage.cpp
    
    ISortingAlgorithm.h
    BubbleSort.h
    InsertionSort.h
    SelectionSort.h
    QuickSort.h
    MergeSort.h
    SortingVisualization.h
    VisualDataStorage.h
    constants.h
)

# Link SFML libraries to your executable
target_link_libraries(${PROJECT_NAME}
PUBLIC
    sfml-window
    sfml-graphics
    boost::boost
)