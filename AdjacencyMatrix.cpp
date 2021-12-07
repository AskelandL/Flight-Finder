#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int m, int n)
{
	myMatrix = new int[m][n];
	numVert = m;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	for (int i = 0; i < numVert; i++) {
		delete myMatrix.at(i);
	}
	delete[] myMatrix[];
}

void AdjacencyMatrix::insertRoute(int from, int to, int weight)
{
	myMatrix[from][to] = weight;
	myMatrix[to][from] = weight;
}

void AdjacencyMatrix::removeRoute(int from, int to, int weight)
{
	myMatrix[from][to] = 0;
	myMatrix[to][from] = 0;
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

	//iterates through graph and prints potential route connections
	for (int i = 0;i < numVert; i++) {
		cout << "airport" << i << " connects to airports: ";
		for (int j = 0; j < numVert; j++) {
			if (myMatrix[i][j]) != 0 ) {
			cout << j << " ";
			}
		}
		cout << "\n";
	}
}

void AdjacencyMatrix::displayMatrix(int from, int to ) {

	for (int i = 0;i < numVert; i++) {
		cout << "airport" << i << " connects to airports: ";
		for (int j = 0; j < numVert; j++) {
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


