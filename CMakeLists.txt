cmake_minimum_required(VERSION 3.0)
project(Chess)

# Add the executable
add_executable(Chess src/main.cpp)

add_library(database src/database/filedatabase/FileDataBase.cpp)

add_executable(tests tests/database/ut_FileDataBase.cpp)
target_link_libraries(tests gtest gtest_main database)