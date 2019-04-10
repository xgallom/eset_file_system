set(files
        src/FileIndexer.cpp
        src/FileIndexerException.cpp
        src/IndexingErrorPresenter.cpp
        )

add_library(file_indexer STATIC ${files})

target_include_directories(file_indexer
        PUBLIC include
        PRIVATE src
        )

target_link_libraries(file_indexer PUBLIC utility)
