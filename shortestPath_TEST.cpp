#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "shortestPath.hpp"
#include <iostream>
#include <vector>

using namespace std;

TEST_CASE("Testing shortestPath"){

    SECTION("dijkstra"){
        
        ifstream file;
        file.open("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;
        int numVertices = readGraph(file, matrix, vLabels, eLabels);
       
        double* dist;
        int* prev;

        dijkstra(matrix, numVertices, 0, dist, prev);

        REQUIRE(dist[0] == 0);
        REQUIRE(dist[1] == 4.5);
        REQUIRE(dist[2] == 10);
        REQUIRE(dist[3] == 3.2);
        REQUIRE(prev[0] == 0);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 0);

        dijkstra(matrix, numVertices, 1, dist, prev);

        REQUIRE(dist[0] == 8.2);
        REQUIRE(dist[1] == 0);
        REQUIRE(dist[2] == 5.5);
        REQUIRE(dist[3] == 8.4);
        REQUIRE(prev[0] == 2);
        REQUIRE(prev[1] == 1);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 2);

        dijkstra(matrix, numVertices, 2, dist, prev);

        REQUIRE(dist[0] == 2.7);
        REQUIRE(dist[1] == 4.2);
        REQUIRE(dist[2] == 0);
        REQUIRE(dist[3] == 2.9);
        REQUIRE(prev[0] == 2);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 2);
        REQUIRE(prev[3] == 2);

        int* path;

		int pathSize = getPath(2, 1, prev, path);

		REQUIRE(pathSize == 3);
        REQUIRE(path[0] == 2);
		REQUIRE(path[1] == 3);
		REQUIRE(path[2] == 1);

        dijkstra(matrix, numVertices, 3, dist, prev);

        REQUIRE(dist[0] == 9.5);
        REQUIRE(dist[1] == 1.3);
        REQUIRE(dist[2] == 6.8);
        REQUIRE(dist[3] == 0);
        REQUIRE(prev[0] == 2);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 3);

        pathSize = getPath(3, 0, prev, path);

		REQUIRE(pathSize == 4);
        REQUIRE(path[0] == 3);
		REQUIRE(path[1] == 1);
		REQUIRE(path[2] == 2);
        REQUIRE(path[3] == 0);
		
    }

    SECTION("dikstra heap"){
        ifstream file;
        file.open("graph.txt");
        int** adj;
        double** weights;
        int* lengths;
        string* vLabels;
        string** eLabels;
        int numVertices = readGraph(file, adj, weights, lengths, vLabels, eLabels);
       
        double* dist;
        int* prev;
        
        dijkstra(adj, weights, lengths, numVertices, 0, dist, prev);
        
        REQUIRE(dist[0] == 0);
        REQUIRE(dist[1] == 4.5);
        REQUIRE(dist[2] == 10);
        REQUIRE(dist[3] == 3.2);
        REQUIRE(prev[0] == 0);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 0);

        dijkstra(adj, weights, lengths, numVertices, 1, dist, prev);

        REQUIRE(dist[0] == 8.2);
        REQUIRE(dist[1] == 0);
        REQUIRE(dist[2] == 5.5);
        REQUIRE(dist[3] == 8.4);
        REQUIRE(prev[0] == 2);
        REQUIRE(prev[1] == 1);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 2);

        dijkstra(adj, weights, lengths, numVertices, 2, dist, prev);

        REQUIRE(dist[0] == 2.7);
        REQUIRE(dist[1] == 4.2);
        REQUIRE(dist[2] == 0);
        REQUIRE(dist[3] == 2.9);
        REQUIRE(prev[0] == 2);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 2);
        REQUIRE(prev[3] == 2);

        dijkstra(adj, weights, lengths, numVertices, 3, dist, prev);

        REQUIRE(dist[0] == 9.5);
        REQUIRE(dist[1] == 1.3);
        REQUIRE(dist[2] == 6.8);
        REQUIRE(dist[3] == 0);
        REQUIRE(prev[0] == 2);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 3);
        
    }

    SECTION("Bellman-Ford"){
        ifstream file;
        file.open("graph.txt");
        int** edgeList;
        double* weights;
        int numEdges;
        string* vLabels;
        string* eLabels;
        int numVertices = readGraph(file, edgeList, weights, numEdges, vLabels, eLabels);
       
        double* dist;
        int* prev;

        int negCycles = bellmanFord(edgeList, weights, numVertices, numEdges, 0, dist, prev);

        REQUIRE(negCycles == -1);
        REQUIRE(dist[0] == 0);
        REQUIRE(dist[1] == 4.5);
        REQUIRE(dist[2] == 10);
        REQUIRE(dist[3] == 3.2);
        REQUIRE(prev[0] == 0);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 0);

        negCycles = bellmanFord(edgeList, weights, numVertices, numEdges, 3, dist, prev);

        REQUIRE(negCycles == -1);
        REQUIRE(dist[0] == 9.5);
        REQUIRE(dist[1] == 1.3);
        REQUIRE(dist[2] == 6.8);
        REQUIRE(dist[3] == 0);
        REQUIRE(prev[0] == 2);
        REQUIRE(prev[1] == 3);
        REQUIRE(prev[2] == 1);
        REQUIRE(prev[3] == 3);

    }

    SECTION("Bellman-Ford with my graph"){
        ifstream file;
        file.open("graph2.txt");
        int** edgeList;
        double* weights;
        int numEdges;
        string* vLabels;
        string* eLabels;
        int numVertices = readGraph(file, edgeList, weights, numEdges, vLabels, eLabels);
       
        double* dist;
        int* prev;
        int* cycle;

        int negCycles = bellmanFord(edgeList, weights, numVertices, numEdges, 0, dist, prev);

        REQUIRE(negCycles == 3);

        int cycleSize = getCycle(negCycles, prev, numVertices, cycle);

        REQUIRE(cycleSize == 5);

        
    }

}