#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

int bellmanFord(const int* const * edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev){
    dist = new double[numVertices];
    prev = new int[numVertices];

    for(int i = 0; i < numVertices; i++){
        dist[i] = numeric_limits<double>::infinity();
        prev[i] = -1;
    }

    dist[source] = 0;
    prev[source] = source;

    int src, dest;
    double weight;
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numEdges; j++){
            src = edges[j][0];
            dest = edges[j][1];
            weight = weights[j];
            if(dist[src] != numeric_limits<double>::infinity() && dist[dest] > dist[src] + weight){
                dist[dest] = dist[src] + weight;
                prev[dest] = src;
            }
        }
    }

    for(int i = 0; i < numEdges; i++){
        src = edges[i][0];
        dest = edges[i][1];
        weight = weights[i];
        if(dist[dest] > dist[src] + weight){
            return dest;
        }
    }

    return -1;
}

int getCycle(int vertex, const int* prev, int numVertices, int*& cycle){
    
}

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev){

    bool* foundMin = new bool[numVertices];
    dist = new double[numVertices];
    prev = new int[numVertices];

    for(int i = 0; i < numVertices; i++){
        dist[i] = numeric_limits<double>::infinity();
        prev[i] = -1;
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
    int size = 1, next = prev[dest];

    if(source == next){
        size = 2;
    }
    else{
        while(next != source){
            if(prev[next] == source){
                size++;
            }
            next = prev[next];
            size++;
        }
    }

    path = new int[size];
    path[0] = source;
    path[size-1] = dest;

    if(size > 2){
        int count = 2;
        next = prev[dest];

        while(next != source){
            path[size-count] = next;
            count++;
            next = prev[next];
        }
        
    }

    return size;
}