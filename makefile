cCXX = g++
CXXFLAGS = -Wall -g

mytest: buffer.o bufferlist.o mytest.cpp
	$(CXX) $(CXXFLAGS) buffer.o bufferlist.o mytest.cpp -o mytest

bufferlist.o: buffer.o bufferlist.h bufferlist.cpp
	$(CXX) $(CXXFLAGS) -c bufferlist.cpp

buffer.o: buffer.h buffer.cpp
	$(CXX) $(CXXFLAGS) -c buffer.cpp

run:
	./mytest

