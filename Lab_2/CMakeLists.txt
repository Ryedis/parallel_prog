cmake_minimum_required(VERSION 3.11)

project(functions CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp:experimental")
endif()

find_package(OpenMP REQUIRED)

add_library(matrix SHARED "matrix.cc")
target_include_directories(matrix PUBLIC "include")

if(OpenMP_CXX_FOUND)
    target_link_libraries(matrix PRIVATE OpenMP::OpenMP_CXX)
endif()

add_executable(console "console/console.cc")
target_link_libraries(console PRIVATE matrix)

if(OpenMP_CXX_FOUND)
    target_link_libraries(console PRIVATE OpenMP::OpenMP_CXX)
endif()

