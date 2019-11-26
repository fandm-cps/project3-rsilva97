CC = g++ -g
CFLAGS = -Wall
COVERAGE = --coverage

all: readGraph_TEST

readGraph_TEST: readGraph_TEST.cpp readGraph.hpp
	$(CC) -o readGraph readGraph_TEST.cpp readGraph.cpp

readGraph_coverage: readGraph_TEST.cpp readGraph.hpp
	$(CC) $(CFLAGS) $(COVERAGE) readGraph_TEST.cpp readGraph.hpp readGraph.cpp 

clean:
	rm readGraph *.o *.hpp.gch *.gcda *.gcno *~ *.png *.css *.html 7/;
