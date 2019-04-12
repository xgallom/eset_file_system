cmake_minimum_required(VERSION 3.2)
project(eset_file_system)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
-Wall \
-Wextra \
-Wshadow \
-Wnon-virtual-dtor \
-Wold-style-cast \
-Wcast-align \
-Wunused \
-Woverloaded-virtual \
-Wpedantic \
-Wsign-conversion \
-Wmisleading-indentation \
-Wduplicated-cond \
-Wlogical-op \
-Wnull-dereference \
-Wuseless-cast \
-Wdouble-promotion \
-Wformat=2 \
-Weffc++ \
-pedantic \
")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
