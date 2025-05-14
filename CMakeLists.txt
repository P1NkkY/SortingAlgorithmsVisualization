cmake_minimum_required(VERSION 3.28)
project(SortingAlgorithmsVisualization LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

# Add your executable
add_executable(${PROJECT_NAME} 
    main.cpp
)

# Link SFML libraries to your executable
target_link_libraries(${PROJECT_NAME}
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network
)