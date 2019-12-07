CC = g++ -g
CFLAGS = -Wall
COVERAGE = --coverage

all: readGraph_TEST shortestPath_TEST matrixDijkstra listDijkstra BinaryHeap_TEST bellmanFord currency

readGraph_TEST: readGraph_TEST.cpp readGraph.hpp
	$(CC) -o readGraph readGraph_TEST.cpp readGraph.cpp

readGraph_cov: readGraph_TEST.cpp readGraph.hpp
	$(CC) $(CFLAGS) $(COVERAGE) readGraph_TEST.cpp readGraph.hpp readGraph.cpp

shortestPath_TEST: shortestPath_TEST.cpp shortestPath.hpp BinaryHeap.o
	$(CC) -o shortestPath shortestPath_TEST.cpp shortestPath.cpp readGraph.cpp BinaryHeap.o

shortestPath_cov: shortestPath_TEST.cpp shortestPath.hpp
	$(CC) $(CFLAGS) $(COVERAGE) shortestPath_TEST.cpp shortestPath.hpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp

shortestPath.o: shortestPath.cpp shortestPath.hpp
	$(CC) -c shortestPath.cpp

readGraph.o: readGraph.cpp readGraph.hpp
	$(CC) -c readGraph.cpp

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.hpp
	$(CC) -c BinaryHeap.cpp

matrixDijkstra: matrixDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o
	$(CC) -o matrixDijkstra matrixDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o

listDijkstra: listDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o
	$(CC) -o listDijkstra listDijkstra.cpp shortestPath.o readGraph.o BinaryHeap.o

bellmanFord: bellmanFord.cpp shortestPath.o readGraph.o BinaryHeap.o
	$(CC) -o bellmanFord bellmanFord.cpp shortestPath.o readGraph.o BinaryHeap.o

currency: currency.cpp shortestPath.o readGraph.o BinaryHeap.o
	$(CC) -o currency currency.cpp shortestPath.o readGraph.o BinaryHeap.o

BinaryHeap_TEST: BinaryHeap_TEST.cpp BinaryHeap.hpp
	$(CC) -o BinaryHeap BinaryHeap_TEST.cpp BinaryHeap.cpp

BinaryHeap_cov: BinaryHeap_TEST.cpp BinaryHeap.hpp
	$(CC) $(CFLAGS) $(COVERAGE) BinaryHeap_TEST.cpp BinaryHeap.hpp BinaryHeap.cpp

clean:
	rm readGraph shortestPath matrixDijkstra listDijkstra BinaryHeap *.o *.hpp.gch *.gcda *.gcno *~ *.png *.css *.html *.gcov a.out;
