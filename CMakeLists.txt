cmake_minimum_required(VERSION 3.13)
project(ComputationalMathLab2 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

find_package(Drogon CONFIG REQUIRED)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
        src/*.cpp
        src/*.hpp
        include/*.hpp
        libs/*.hpp
        libs/*.cpp
)

add_executable(ComputationalMathLab2 ${sources})
target_include_directories(ComputationalMathLab2 PRIVATE src include libs)
target_link_libraries(ComputationalMathLab2 PRIVATE Drogon::Drogon)