#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev){

    bool* foundMin = new bool[numVertices];
    dist = new double[numVertices];
    prev = new int[numVertices];

    for(int i = 0; i < numVertices; i++){
        dist[i] = numeric_limits<double>::infinity();
        prev[i] = 0;
        foundMin[i] = false;
    }
    dist[source] = 0;
    prev[source] = source;

    int minVertex;
    double minVal;

    for(int i = 0; i < numVertices; i++){
        
        minVertex = -1;
        minVal = numeric_limits<double>::infinity();

        for(int j = 0; j < numVertices; j++){
            if(!foundMin[j] && minVal > dist[j]){
                minVal = dist[j];
                minVertex = j;
            }
        }
        
        foundMin[minVertex] = true;

        for(int k = 0; k < numVertices; k++){
            if(matrix[minVertex][k] > 0 && !foundMin[k] && matrix[minVertex][k] != numeric_limits<double>::infinity()){
                if(matrix[minVertex][k] + dist[minVertex] < dist[k]){
                    dist[k] = matrix[minVertex][k] + dist[minVertex];
                    prev[k] = minVertex;
                }
            }
        }

    }

    delete[] foundMin;
   
}

int getPath(int source, int dest, const int* prev, int*& path){
    
}