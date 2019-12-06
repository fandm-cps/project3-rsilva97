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

    file.open(argv[1], ios_base::in); //the name of a file containing a graph
    outFile.open(argv[2], ios_base::out); //the name of the output file
	string srcVertex = argv[3]; //the name of the source vertex
	string destVertex = argv[4]; //the name of the destination vertex

    int** adj;
    double** weights;
    int* lengths;
    string* vLabels;
    string** eLabels;
    double* dist;
    int* prev;
    int* path;

    int numVertices = readGraph(file, adj, weights, lengths, vLabels, eLabels);

    int srcVertexIdx = -1, destVertexIdx = -1;
    for(int i = 0; i < numVertices; i++){
        if(vLabels[i] == srcVertex){
            srcVertexIdx = i;
        }
        if(vLabels[i] == destVertex){
            destVertexIdx = i;
        }
    }
    
    auto startTime = std::chrono::system_clock::now();

    dijkstra(adj, weights, lengths, numVertices, srcVertexIdx, dist, prev);

    int pathLength = getPath(srcVertexIdx, destVertexIdx, prev, path);
/*
    for(int i = 0; i < pathLength; i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    */
    outFile << numVertices << " " << pathLength-1 << endl;
    for(int i = 0; i < numVertices; i++){
        outFile << vLabels[i] << endl;
    }
    
    for(int i = 0; i < pathLength-1; i++){
        int from = path[i], to = path[i+1], idx;

        for(int j = 0; j < lengths[from]; j++){
            if(adj[from][j] == to){
                idx = j;
            }
        }

        outFile << from << " " << to << " " << weights[path[i]][idx] << " " << eLabels[path[i]][idx] << endl;
    }
    

    file.close();
	outFile.close();

    auto endTime = std::chrono::system_clock::now();
    auto durMicrosecs = chrono::duration_cast<chrono::microseconds>(endTime-startTime);
    double elapsedTime = durMicrosecs.count();

    cout << "Weight of shortest path: " << dist[destVertexIdx] << endl;
    cout << "Duration of Dijkstra's algorithm: " << elapsedTime << " microseconds." << endl;
}