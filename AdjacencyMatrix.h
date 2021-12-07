#pragma once
#include "Definitions.h"
#include <vector>
#include <array>
using namespace std;

class AdjacencyMatrix {

private:
    int numVert;
    int myMatrix[][];

public:
    AdjacencyMatrix(int m, int n);
    ~AdjacencyMatrix();
    void insertRoute(int from, int to, int weight);
    void removeRoute(int from, int to, int weight);
    void displayMatrix();
    bool isRoute(int from, int to);
};
};