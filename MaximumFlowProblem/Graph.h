#pragma once

#include <vector>
#include <queue>
#include "AdjacencyList.h"

using namespace std;

class Graph {

public:
	Graph(int _vertexCount);

	Edge* addEdge(int _source, int _destination, int _weight);
	Edge* edgeExists(int _source, int _destination);
	Edge* getEdge(int _source, int _destination);
	void initializeFlow();
	vector<int> BFSQueue(int _source, int _destination);
	int FordFulkersonAlgorithm();
	void print();

	~Graph();

private:
	int vertexCount;
	vector<AdjacencyList*> list;
	Graph* flowGraph;

};

