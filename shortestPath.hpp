#ifndef SHORTEST_PATH
#define SHORTEST_PATH

#include "readGraph.hpp"

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev);

int getPath(int source, int dest, const int* prev, int*& path);

#endif