Files included in this project:

readGraph.hpp/.cpp
shortestPath.hpp/.cpp
BinaryHeap.hpp/.cpp
bellmanFord.cpp
currency.cpp
readGraph_TEST.cpp
shortestPath_TEST.cpp
BinaryHeap_TEST.cpp
Makefile
readme.txt
graph.txt
graph2.txt
exchangerates.txt
bgraph.txt

Below is a list of the commands that should be written to the terminal in order to run unit testing:

readGraph: ./readGraph
shortestPath: ./shortestPath
BinaryHeap: ./BinaryHeap

For the following commands, replace the parameters in <> by their corresponding values.

To run bellmanFord: In the terminal type "./bellmanFord <graph filename> <output filename> <starting vertex> <destination vertex>"

To run matrixDijkstra: In the terminal type "./matrixDijkstra <graph filename> <output filename> <starting vertex> <destination vertex>"

To run listDijkstra: In the terminal type "./listDijkstra <graph filename> <output filename> <starting vertex> <destination vertex>"

To run currency: In the terminal type "./currency <graph filename> <output filename> <starting vertex> <destination vertex> <transaction cost>"

NOTES: 

(1) When performing the currency exchange algorithm, my program outputs a file with similar format to that of the examples from te project description. However, it uses different edges and returns a negative exchange rate for the problem without a negative cycle;
