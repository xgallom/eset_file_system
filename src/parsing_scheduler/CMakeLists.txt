set(files
        src/ParallelParsingScheduler.cpp
        src/ParallelParsingSchedulerThreadFlags.cpp
        src/ParsingResult.cpp
        src/ParsingScheduler.cpp
        src/ParsingSchedulerBuilder.cpp
        src/SequentialParsingScheduler.cpp
        )

add_library(parsing_scheduler STATIC ${files})

target_include_directories(parsing_scheduler
        PUBLIC include
        PRIVATE src
        )

target_link_libraries(parsing_scheduler PUBLIC file_indexer file_parser PRIVATE pthread)
