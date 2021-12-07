#pragma once
#include <vector>
#include <set>
#include "AdjacencyMatrix.h"

// two algorithms:
	// Dijkstra's
	// Bellman Ford's

int Dijkstra(AdjacencyMatrix graph, int from, int to);
int BellmanFord(AdjacencyMatrix graph, int from, int to);