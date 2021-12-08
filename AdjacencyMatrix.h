#pragma once
#include "Definitions.h"
#include <vector>
#include <array>
#include <set>
using namespace std;

class AdjacencyMatrix {

private:
    int numVert;
    vector<vector<int>> myMatrix;

public:
    AdjacencyMatrix(int m, int n);
    ~AdjacencyMatrix();
    vector<vector<int>> getMatrix();
    int getVertices();
    void insertRoute(int from, int to, int weight);
    void removeRoute(int from, int to, int weight);
    void displayMatrix();
    void displayAirport(int from, int to);
    bool isRoute(int from, int to);
    pair<int, vector<int>> Dijkstra(int from, int to);
    pair<int, vector<int>> BellmanFord(int from, int to);
};