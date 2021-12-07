#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int m, int n)
{
	myMatrix.resize(m, vector<int> (n, 0));
	numVert = m;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	for (int i = 0; i < numVert; i++) {
		delete myMatrix.at(i);
	}
	delete[] myMatrix[];
}

Vector<vector<int>> AdjacencyMatrix::getMatrix()
{
	return myMatrix;
}

int AdjacencyMatrix::getVertices()
{
	return numVert;
}

void AdjacencyMatrix::insertRoute(int from, int to, int weight)
{
	myMatrix[from][to] = weight;
}

void AdjacencyMatrix::removeRoute(int from, int to, int weight)
{
	myMatrix[from][to] = 0;
}

void AdjacencyMatrix::displayMatrix()
{

	//displays entire matrix
	cout << "Potential Routes include: "
		for (int i = 0; i < numVert; i++) {
			for (int j = 0; j < numVert; j++) {
				cout < myMatrix[i][j] << " ";
			}
			cout << "\n";
		}
}

//show nodes connected to one specified airport
void AdjacencyMatrix::displayAirport(int from, int to ) {

	for (int i = from;i < to; i++) {
		cout << "airport" << i << " connects to airports: ";
		for (int j = from; j < to; j++) {
			if (myMatrix[i][j]) != 0 ) {
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


