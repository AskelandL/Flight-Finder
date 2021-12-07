#include "findPath.h"

int Dijkstra(AdjacencyMatrix& graph, int from, int to) {
	// declare vectors and sets
	set<int> visited;
	set<int> notVisited;
	vector<int> distance(graph.numVert, 9999999999);
	vector<int> previous(graph.numVert, -1);

	visited.insert(from);
	distance[from] = 0;
	for (int i = 0; i < graph.numVert; i++) {
		if (i != from) {
			notVisited.insert(i);
		}
	}

	for (auto v : notVisited) {
		for (int i = 0; i < graph.myMatrix[from].size(); i++) {
			if (graph.myMatrix[from][i] == v) {
				distance[v] = graph.myMatrix[from][i];
				previous[v] = from;
				break;
			}
		}
	}

	while (!notVisited.empty()) {
		int minWeight = 9999999999;
		int minVertex;
		for (auto u : notVisited) {
			if (distance[u] < minWeight) {
				minVertex = u;
				minWeight = distance[u];
			}
		}

		notVisited.erase(minVertex);
		visited.insert(minVertex);

		for (auto v : notVisited) {
			for (int i = 0; i < graph.myMatrix[minVertex].size(); i++) {
				if (graph.myMatrix[minVertex][i] == v) {
					if (distance[minVertex] + graph.myMatrix[minVertex][i] < distance[v]) {
						distance[v] = distance[minVertex] + graph.myMatrix[minVertex][i];
						previous[v] = minVertex;
					}
					break;
				}
			}
		}
	}

	return distance[to];
}
int BellmanFord(AdjacencyMatrix& graph, int from, int to) {
	vector<int> distance(graph.numVert, 9999999999);
	vector<int> previous(graph.numVert, -1);
	distance[from] = 0;
	previous[from] = NULL;

	for (int i = 0; i < graph.numVert; i++) {
		for (int j = 0; j < graph.myMatrix[i].size(); j++) {
			if (graph.myMatrix[i][j] != 0) {
				int tempDist = distance[j] + graph.myMatrix[i][j];
				if (tempDist < distance[i]) {
					distance[i] = tempDist;
					previous[i] = j;
				}
			}

		}
	}

	return distance[to];
}