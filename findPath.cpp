int Dijkstra(AdjacencyMatrix graph, int from, int to) {
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
int BellmanFord(AdjacencyMatrix graph, int from, int to) {
	return 0;
}