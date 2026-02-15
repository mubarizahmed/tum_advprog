CXX = g++
CXXFLAGS = -g -Wall -std=c++20

all: caseTrack

caseTrack: caseTrack.cpp helper.o
	$(CXX) $(CXXFLAGS) -o ../build/caseTrack caseTrack.cpp ../build/helper.o

helper.o: helper.cpp helper.hpp build
	$(CXX) $(CXXFLAGS) -c -o ../build/helper.o helper.cpp

build:
	mkdir -p ../build

clean:
	rm -rf ../build/helper.o ../build/caseTrack
