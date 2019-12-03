#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "readGraph.hpp"
#include "shortestPath.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	ifstream file;
	ofstream outFile;

	file.open(argv[1], ios_base::in);
	outFile.open(argv[2], ios_base::out);
	string srcVertex = argv[3];
	string destVertex = argv[4];

    double** matrix;
    string* vLabels;
    string** eLabels;
    double* dist;
    int* prev;
    int* path;

    auto startTime = std::chrono::system_clock::now();

    int numVertices = readGraph(file, matrix, vLabels, eLabels);

    int srcVertexIdx = -1, destVertexIdx = -1;
    for(int i = 0; i < numVertices; i++){
        if(vLabels[i] == srcVertex){
            srcVertexIdx = i;
        }
        if(vLabels[i] == destVertex){
            destVertexIdx = i;
        }
    }

    dijkstra(matrix, numVertices, srcVertexIdx, dist, prev);

    int pathLength = getPath(srcVertexIdx, destVertexIdx, prev, path);

    outFile << numVertices << " " << pathLength-1 << endl;
    for(int i = 0; i < numVertices; i++){
        outFile << vLabels[i] << endl;
    }
    for(int i = 0; i < pathLength-1; i++){
        outFile << path[i] << " " << path[i+1] << " " << matrix[path[i]][path[i+1]] << " " << eLabels[path[i]][path[i+1]] << endl;
    }
	
    file.close();
	outFile.close();

    auto endTime = std::chrono::system_clock::now();
    auto durMicrosecs = chrono::duration_cast<chrono::microseconds>(endTime-startTime);
    double elapsedTime = durMicrosecs.count();

    cout << "Weight of shortest path: " << dist[destVertexIdx] << endl;
    cout << "Duration of Dijkstra's algorithm: " << elapsedTime << " microseconds." << endl;

}