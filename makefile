# Built based on https://stackoverflow.com/questions/48791883/best-practice-for-building-a-make-file
# When using :=, the value of the variable is evaluated once and stored. 
# When using =, the value of the variable is evaluated everytime it's required. 
# "@mkdir -p ${VAR}" will create missing directories if needed. Very convenient. 

# These can be reassigned upon calling makefile. The values below are defaults. eg: make BUILD=release
BUILD := debug
COMPILER := gcc

BUILDPATH	:= build/${BUILD}
OBJPATH		:= obj/${BUILD}
INCPATH		:= include
SRCPATH		:= src

CXX.gcc		:= g++
CXX.clang	:= clang++

CXX := ${CXX.${COMPILER}}

CXXFLAGS.gcc.debug	 	:= -O0 -g
CXXFLAGS.gcc.release 	:= -O2
CXXFLAGS.gcc 		 	:= ${CXXFLAGS.gcc.${BUILD}}
CXXFLAGS.clang.debug	:= -O0 -g
CXXFLAGS.clang.release	:= -O2
CXXFLAGS.clang			:= ${CXXFLAGS.clang.${BUILD}}

CXXFLAGS := ${CXXFLAGS.${COMPILER}} -std=c++14 -Wall -I${INCPATH}

objects := ${patsubst ${SRCPATH}/%.cpp, ${OBJPATH}/%.o, ${wildcard ${SRCPATH}/*.cpp}}

headers := ${INCPATH}/*.h

chess: ${objects}
	@mkdir -p ${BUILDPATH}
	${CXX} -o ${BUILDPATH}/$@ $^ ${CXXFLAGS}

# The second colon leads to prerequisites. The cpp file must exist for this to be performed in this case... I think. 
${objects}: ${OBJPATH}/%.o: ${SRCPATH}/%.cpp
	@mkdir -p ${OBJPATH}
	${CXX} -c -o $@ $< ${CXXFLAGS}
# Phony prevents this from being attempted to be built because it's not a file, simply an action. 
# The "-" before "rm" allows this to execute without throwing error if something doesnt exist. 
.PHONY: clean gtest

gtest:
	@mkdir -p build/cmake
	-(cd build/cmake && cmake ../../ -DCMAKE_BUILD_TYPE=Debug)
	make --directory=build/cmake

clean:
	-rm -r obj build
