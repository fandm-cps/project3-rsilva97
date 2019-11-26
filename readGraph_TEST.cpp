#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

TEST_CASE("Testing ReadGraph"){

    SECTION("functions"){
        
        ifstream file;
        file.open("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;

        int numVertices = readGraph(file, matrix, vLabels, eLabels);

        REQUIRE(numVertices == 4);

        /*
        for(int i = 0; i < numVertices; i++){
            cout << "Vertex: " << vLabels[i] << endl;
            cout << "Edges: " << endl;
            for(int j = 0; j < numVertices; j++){
                cout << eLabels[i][j] << endl;
            } 
            cout << endl;
        }
       
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < numVertices; j++){
                cout << matrix[i][j] << " ";
            }
            cout<<endl;
        }   
        */
       
    }

}

/*
        int vertices, edges;
        vector<string> vertexLabels, edgeLabels;
        vector<int> 
        string label; 

        ifstream file;

        file.open("graph.txt", ios_base::in);

        if(file.is_open()){
            file >> vertices >> edges;

            int i = 0;
            while(file >> label && i < vertices){
                vertexLabels.push_back(label);
                i++;
            }

            REQUIRE(vertices == 4);
            REQUIRE(edges == 6);
            REQUIRE(vertexLabels[0] == "GingerbreadPlumTrees");
            REQUIRE(vertexLabels[3] == "PeanutBrittleHouse");
            REQUIRE(vertexLabels.size() == 4);

            file.close();
        }
        else{
            cout << "open() failed: check if file is in right folder" << endl;
        }
        */