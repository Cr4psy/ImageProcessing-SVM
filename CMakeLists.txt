cmake_minimum_required(VERSION 2.8.3)
project(cpp_assignment)

find_package(OpenCV REQUIRED)

set(CMAKE_BUILD_TYPE DEBUG)

## Declare a cpp executable. // Add your additional files here next to main.cpp
add_executable(main main.cpp header.hpp dataset.h dataset.cpp histogramViewer.cpp histogramViewer.hpp imageProcessing.hpp imageProcessing.cpp histogramProcessor.cpp histogramProcessor.hpp svmclassification.cpp svmclassification.hpp color.h ${OpenCV_HEADERS})
target_link_libraries(main ${OpenCV_LIBS}) 

