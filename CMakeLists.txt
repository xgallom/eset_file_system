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

set(files
        src/Arguments/Arguments.cpp src/Arguments/Arguments.h
        src/Arguments/ArgumentsConfig.h
        src/Arguments/ArgumentsException.cpp src/Arguments/ArgumentsException.h
        src/Arguments/ArgumentsUsage.h
        src/FileIndexer/FileIndex.h
        src/FileIndexer/FileIndexer.cpp src/FileIndexer/FileIndexer.h
        src/FileIndexer/FileIndexerError.h
        src/FileIndexer/FileIndexerException.cpp src/FileIndexer/FileIndexerException.h
        src/FileParser/FileParser.cpp src/FileParser/FileParser.h
        src/FileParser/FileParserException.cpp src/FileParser/FileParserException.h
        src/FileParser/FileParserImpl.cpp src/FileParser/FileParserImpl.h
        src/FileParser/FileReader.cpp src/FileParser/FileReader.h
        src/FileParser/KeyValidator.cpp src/FileParser/KeyValidator.h
        src/FileParser/SearchIndex.cpp src/FileParser/SearchIndex.h
        src/FileParser/SuffixWaitingQueue.cpp src/FileParser/SuffixWaitingQueue.h
        src/ParsingScheduler/ParallelParsingScheduler.cpp src/ParsingScheduler/ParallelParsingScheduler.h
        src/ParsingScheduler/ParsingResult.cpp src/ParsingScheduler/ParsingResult.h
        src/ParsingScheduler/ParsingScheduler.cpp src/ParsingScheduler/ParsingScheduler.h
        src/ParsingScheduler/ParsingSchedulerBuilder.cpp src/ParsingScheduler/ParsingSchedulerBuilder.h
        src/ParsingScheduler/SequentialParsingScheduler.cpp src/ParsingScheduler/SequentialParsingScheduler.h
        src/Utility/Optional.h
        src/Utility/Queue.h
        src/OutputPresenter.cpp src/OutputPresenter.h
        src/Application.cpp src/Application.h
        src/main.cpp
        src/ParsingScheduler/ParallelParsingSchedulerThreadFlags.h src/ParsingScheduler/ParallelParsingSchedulerThreadFlags.cpp)

add_executable(eset_file_system ${files})

target_include_directories(eset_file_system PRIVATE src)
target_link_libraries(eset_file_system PRIVATE pthread)