cmake_minimum_required(VERSION 3.10)

set(This UniProjectChess)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(googletest)

file(GLOB Headers
	"include/*.h"
)
file(GLOB Sources
	"src/*.cpp"
)

add_library(${This} STATIC ${Sources} ${Headers})
target_include_directories(${This} PUBLIC include)

add_subdirectory(tests)
