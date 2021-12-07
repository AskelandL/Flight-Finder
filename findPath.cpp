#pragma once
#include <vector>
#include <set>
#include "AdjacencyMatrix.h"

int Dijkstra(AdjacencyMatrix& graph, int from, int to) {
	// declare vectors and sets
	set<int> visited;
	set<int> notVisited;
	vector<int> distance(graph.getVertices(), INF);
	vector<int> previous(graph.getVertices(), -1);

	visited.insert(from);
	distance[from] = 0;
	for (int i = 0; i < graph.getVertices(); i++) {
		if (i != from) {
			notVisited.insert(i);
		}
	}
	//cout << "  checkpoint #2" << endl;
	for (auto v : notVisited) {
		if (graph.getMatrix()[from][v] != 0) {
			int tempDist = graph.getMatrix()[from][v];
			distance[v] = tempDist;
			previous[v] = from;
		}
	}
	//cout << "   checkpoint #3" << endl;
	while (!notVisited.empty()) {
		int minWeight = INF;
		int minVertex;
		for (auto u : notVisited) {
			if (distance[u] < minWeight) {
				minVertex = u;
				minWeight = distance[u];
			}
		}
		//cout << "    checkpoint #4" << endl;
		notVisited.erase(minVertex);
		visited.insert(minVertex);

		for (auto v : notVisited) {
			for (int i = 0; i < graph.getMatrix()[minVertex].size(); i++) {
				if (graph.getMatrix()[minVertex][i] != 0) {
					if (distance[minVertex] + graph.getMatrix()[minVertex][i] < distance[v]) {
						distance[v] = distance[minVertex] + graph.getMatrix()[minVertex][i];
						previous[v] = minVertex;
					}
					break;
				}
			}
		}
		//cout << "     checkpoint #5" << endl;
	}

	return distance[to];
}
int BellmanFord(AdjacencyMatrix& graph, int from, int to) {
	vector<int> distance(graph.getVertices(), INF);
	vector<int> previous(graph.getVertices(), -1);
	distance[from] = 0;
	previous[from] = NULL;

	for (int i = 0; i < graph.getVertices(); i++) {
		for (int j = 0; j < graph.getMatrix()[i].size(); j++) {
			if (graph.getMatrix()[i][j] != 0) {
				int tempDist = distance[j] + graph.getMatrix()[i][j];
				if (tempDist < distance[i]) {
					distance[i] = tempDist;
					previous[i] = j;
				}
			}
		}
	}

	return distance[to];
}