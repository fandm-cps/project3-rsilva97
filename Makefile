CC = g++ -g
CFLAGS = -Wall
COVERAGE = --coverage

all: readGraph_TEST shortestPath_TEST

readGraph_TEST: readGraph_TEST.cpp readGraph.hpp
	$(CC) -o readGraph readGraph_TEST.cpp readGraph.cpp

readGraph_cov: readGraph_TEST.cpp readGraph.hpp
	$(CC) $(CFLAGS) $(COVERAGE) readGraph_TEST.cpp readGraph.hpp readGraph.cpp

shortestPath_TEST: shortestPath_TEST.cpp shortestPath.hpp
	$(CC) -o shortestPath shortestPath_TEST.cpp shortestPath.cpp readGraph.cpp

shortestPath_cov: shortestPath_TEST.cpp shortestPath.hpp
	$(CC) $(CFLAGS) $(COVERAGE) shortestPath_TEST.cpp shortestPath.hpp shortestPath.cpp readGraph.cpp

clean:
	rm readGraph shortestPath *.o *.hpp.gch *.gcda *.gcno *~ *.png *.css *.html 7/;
