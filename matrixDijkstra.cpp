#include <iostream>
#include <fstream>
#include <string>
#include "readGraph.hpp"
#include "shortestPath.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	ifstream file;
	ofstream outFile;

	file.open(argv[1], ios_base::in);
	outFile.open(argv[2], ios_base::out);
	string sVertex = argv[3];
	string dVertex = argv[4];

    double** matrix;
    string* vLabels;
    string** eLabels;
    double* dist;
    int* prev;
    int* path;

    int numVertices = readGraph(file, matrix, vLabels, eLabels);

    int sVertexNum = -1, dVertexNum = -1;
    for(int i = 0; i < numVertices; i++){
        if(vLabels[i] == sVertex){
            sVertexNum = i;
        }
        if(vLabels[i] == dVertex){
            sVertexNum = i;
        }
    }

    dijkstra(matrix, numVertices, sVertexNum, dist, prev);
    int numPath = getPath(sVertexNum, dVertexNum, prev, path);

    outFile << numVertices << " " << numPath << endl;
    for(string vertex : vLabels){
        outFile << vertex << endl;
    }
    for(int i = 0; i < numPath; i++){
        outFile << eLabels[path[i]] << endl;
    }
	
	outFile.close();

}