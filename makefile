CXX=g++
CXXFLAGS=-Wall -I/usr/include/cppcon
LDLIBS=-lmysqlcppconn -lstdc++
LDFLAGS=-L/usr/lib

SRCFILES = $(wildcard src/*.cpp)
OBJS = main.o

all: clean build main

build: $(SRCFILES)
	$(CXX) $(CXX_FLAGS) -c $(SRCFILES)

main: $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	rm -rf *.o main
