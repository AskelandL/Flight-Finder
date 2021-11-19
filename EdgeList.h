#pragma once
#include <vector>
using namespace std;

class EdgeList {
    // private variables etc

public:
    class Iterator;
    void insertEdge(int from, int to, int weight);
    vector<int> getAdjacent(int vertex);

    class Iterator{
        // private variables etc
    public:
        Iterator(const EdgeList& graph);
        Iterator& operator++();
    };
};