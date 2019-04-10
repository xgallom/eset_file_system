set(files
        src/ExceptionPresenter.cpp
        )

add_library(utility STATIC ${files})

target_include_directories(utility
        PUBLIC include
        PRIVATE src
        )