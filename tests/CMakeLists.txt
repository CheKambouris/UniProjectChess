cmake_minimum_required(VERSION 3.10)

set(This UniProjectChessTests)

file(GLOB Sources *.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    UniProjectChess
)

add_test(
    NAME ${This}
    COMMAND ${This}
)