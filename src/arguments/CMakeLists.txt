set(files
        src/Arguments.cpp
        src/ArgumentsException.cpp
        src/ArgumentsUsagePresenter.cpp
        )

add_library(arguments STATIC ${files})

target_include_directories(arguments
        PUBLIC include
        PRIVATE src
        )
