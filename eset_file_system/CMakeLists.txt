set(files
        src/Application.cpp
        src/main.cpp
        )

add_executable(eset_file_system ${files})

target_include_directories(eset_file_system PRIVATE src)

target_link_libraries(eset_file_system PRIVATE arguments parsing_scheduler)
