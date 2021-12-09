#include "AdjacencyMatrix.h"
#include <iostream>
using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int nodes)
{
	myMatrix.resize(nodes, vector<int> (nodes, 0));
	numVert = nodes;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	myMatrix.clear();
	
}

vector<vector<int>>& AdjacencyMatrix::getMatrix()
{
	return myMatrix;
}

int AdjacencyMatrix::getVertices()
{
	return numVert;
}

void AdjacencyMatrix::insertRoute(int from, int to, int weight)
{
	myMatrix.at(from).at(to) = weight;
}

void AdjacencyMatrix::removeRoute(int from, int to, int weight)
{
	myMatrix[from][to] = 0;
}

void AdjacencyMatrix::displayMatrix()
{

	//displays entire matrix
	cout << "Potential Routes include: ";
		for (int i = 0; i < numVert; i++) {
			for (int j = 0; j < numVert; j++) {
				cout << myMatrix[i][j] << " ";
			}
			cout << "\n";
		}
}

//show nodes connected to one specified airport
void AdjacencyMatrix::displayAirport(int from, int to ) {

	for (int i = from;i < to; i++) {
		cout << "airport" << i << " connects to airports: ";
		for (int j = from; j < to; j++) {
			if (myMatrix[i][j] != 0 ) {
			cout << j << " ";
			}
		}
		cout << "\n";
	}
}


bool AdjacencyMatrix::isRoute(int from, int to)
{
	if (myMatrix[from][to] != 0) {
		return true;
	}
	else {
		return false;
	}
}

pair<int, vector<int>> AdjacencyMatrix::Dijkstra(int from, int to) {
	// declare vectors and sets
	set<int> visited;
	set<int> notVisited;
	vector<int> distance(getVertices(), INF);
	vector<int> previous(getVertices(), -1);

	visited.insert(from);
	distance[from] = 0;
	for (int i = 0; i < getVertices(); i++) {
		if (i != from) {
			notVisited.insert(i);
		}
	}
	for (auto v : notVisited) {
		previous[v] = from;
		if (getMatrix()[from][v] != 0) {
			int tempDist = getMatrix()[from][v];
			distance[v] = tempDist;
		}
	}
	while (!notVisited.empty()) {
		int minWeight = INF;
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
			if (getMatrix()[minVertex][v] != 0) {
				if (distance[minVertex] + getMatrix()[minVertex][v] < distance[v]) {
					distance[v] = distance[minVertex] + getMatrix()[minVertex][v];
					previous[v] = minVertex;
				}
			}
		}
	}

	vector<int> path; // to -> from
	path.push_back(previous[to]);
	while (path.at(path.size() - 1) != from && path.at(path.size() - 1) != -1) {
		path.push_back(previous[path.at(path.size() - 1)]);
	}
	return make_pair(distance[to], path);
}
pair<int, vector<int>> AdjacencyMatrix::BellmanFord(int from, int to) {
	vector<int> distance(getVertices(), INF);
	vector<int> previous(getVertices(), -1);
	distance[from] = 0;
	previous[from] = -1;

	for (int i = 0; i < getVertices() - 1; i++) {
		for (int u = 0; u < getMatrix().size(); u++) {
			for (int v = 0; v < getMatrix()[u].size(); v++) {
				if (getMatrix()[u][v] != 0) {
					int tempDist = distance[u] + getMatrix()[u][v];
					if (tempDist < distance[v]) {
						distance[v] = tempDist;
						previous[v] = u;
					}
				}
			}
		}
	}

	vector<int> path; // to -> from
	path.push_back(previous[to]);
	while (path.at(path.size() - 1) != from && path.at(path.size() - 1) != -1) {
		path.push_back(previous[path.at(path.size() - 1)]);
	}
	return make_pair(distance[to], path);
}

string AdjacencyMatrix::convert(int node) {
	string result = "";
	if (node > NODES) {
		cout << "too big! " << node << endl;
		return "ZZZ";
	}
	for (int i = 0; i < NAME_LEN; i++) {
		result += (node % 26) + (int)'A';
		node /= 26;
	}
	return result;
}

int AdjacencyMatrix::convert(string node) {
	// assumes input is correct (node of length NAME_LEN, only alpha)
	int result = 0;
	for (int i = 0; i < NAME_LEN; i++) {
		result += (node.at(i) - 'A') * pow(26, i);
	}
	return result;
}