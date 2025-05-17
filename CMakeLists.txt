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
    ISorting.cpp
    BubbleSort.cpp
    InsertionSort.cpp
    SelectionSort.cpp
    QuickSort.cpp
    MergeSort.cpp
    Visualization.cpp
    
    ISorting.h
    BubbleSort.h
    InsertionSort.h
    SelectionSort.h
    QuickSort.h
    MergeSort.h
    Visualization.h
)

# Link SFML libraries to your executable
target_link_libraries(${PROJECT_NAME}
PUBLIC
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network
    boost::boost
)