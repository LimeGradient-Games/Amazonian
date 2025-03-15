cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(AmazonianGame VERSION 0.0.1 LANGUAGES CXX)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

include(cmake/CPM.cmake)
CPMAddPackage("gh:fmtlib/fmt#11.1.4")
CPMAddPackage("gh:gabime/spdlog@1.15.1")
CPMAddPackage("gh:jeremy-rifkin/cpptrace#v0.7.3")
CPMAddPackage("gh:raysan5/raylib#master")

target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_link_libraries(${PROJECT_NAME} PRIVATE
    fmt
    spdlog
    cpptrace::cpptrace
    raylib
)