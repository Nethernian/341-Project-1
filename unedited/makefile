CXX = g++
CXXFLAGS = -Wall -g

main: buffer.o bufferlist.o main.cpp
	$(CXX) $(CXXFLAGS) buffer.o bufferlist.o main.cpp -o main

bufferlist.o: buffer.o bufferlist.h bufferlist.cpp
	$(CXX) $(CXXFLAGS) -c bufferlist.cpp

buffer.o: buffer.h buffer.cpp
	$(CXX) $(CXXFLAGS) -c buffer.cpp

run:
	./main

