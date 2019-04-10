cmake_minimum_required(VERSION 3.13)
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

add_subdirectory(utility)
add_subdirectory(arguments)
add_subdirectory(file_indexer)
add_subdirectory(file_parser)
add_subdirectory(parsing_scheduler)
add_subdirectory(eset_file_system)
