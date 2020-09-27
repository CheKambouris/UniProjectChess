IDIR=include
CC=g++
CFLAGS=-I$(IDIR)

BUILDPATH=build
OBJPATH=obj
SRCPATH=src

chess: src/*.cpp
	g++ -o build/$@ $^ -Iinclude

# %.o: $(SRCPATH)/%.cpp
# 	$(CC) -c -o $(OBJPATH)/$@ $^ $(DEP)

# chess: %.o
# 	$(CC) -o $(BUILDPATH)/$@ $(OBJPATH)$^ $(DEP)
