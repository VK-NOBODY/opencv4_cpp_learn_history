cmake_minimum_required(VERSION 3.28)
project(git_opencv_report)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR "H:\\Applications\\opencv_4.10.0\\opencv\\mingw_build\\install")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(git_opencv_report main.cpp)
target_link_libraries(git_opencv_report ${OpenCV_LIBS})