#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "shortestPath.hpp"
#include <iostream>
#include <vector>

using namespace std;

TEST_CASE("Testing shortestPath"){

    SECTION("functions"){
        
        ifstream file;
        file.open("graph1.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;
        int numVertices = readGraph(file, matrix, vLabels, eLabels);
       
        double* dist;
        int* prev;

        dijkstra(matrix, numVertices, 0, dist, prev);

        REQUIRE(dist[0] == 0);
        REQUIRE(dist[1] == 4);
        REQUIRE(dist[2] == 3);
        REQUIRE(dist[3] == 5);
        REQUIRE(dist[4] == 7);
        REQUIRE(dist[5] == 10);

        REQUIRE(prev[0] == 0);
        REQUIRE(prev[1] == 2);
        REQUIRE(prev[2] == 0);
        REQUIRE(prev[3] == 2);
        REQUIRE(prev[4] == 1);
        REQUIRE(prev[5] == 3);

        int* path;

		int pathSize = getPath(0, 3, prev, path);

		REQUIRE(pathSize == 3);
		REQUIRE(path[0] == 0);
		REQUIRE(path[1] == 2);
		REQUIRE(path[2] == 3);

    }

}