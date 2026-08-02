cmake_minimum_required(VERSION 3.28)
project(SortingAlgorithmsVisualization LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# Add your executable
add_executable(
  ${PROJECT_NAME}
  main.cpp
  sorting/include/bubble_sort.h
  sorting/include/insertion_sort.h
  sorting/include/selection_sort.h
  sorting/include/quick_sort.h
  sorting/include/merge_sort.h
  sorting/src/bubble_sort.cpp
  sorting/src/insertion_sort.cpp
  sorting/src/selection_sort.cpp
  sorting/src/quick_sort.cpp
  sorting/src/merge_sort.cpp
  ISortingAlgorithm.cpp
  SortingVisualization.cpp
  VisualDataStorage.cpp
  ISortingAlgorithm.h
  SortingVisualization.h
  VisualDataStorage.h
  constants.h)

# Link SFML libraries to your executable
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-window sfml-graphics
                                             boost::boost)
