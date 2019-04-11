set(files
        src/FileParser.cpp
        src/FileParserException.cpp
        src/FileParserImpl.cpp
        src/FileReader.cpp
        src/KeyValidator.cpp
        src/SearchIndex.cpp
        src/SearchResultsPresenter.cpp
        src/SuffixWaitingQueue.cpp
        )

add_library(file_parser STATIC ${files})

target_include_directories(file_parser
        PUBLIC include
        PRIVATE src
        )

target_link_libraries(file_parser PUBLIC utility)
