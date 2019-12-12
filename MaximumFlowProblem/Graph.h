#pragma once

#include <vector>
#include <queue>
#include "Utilities.h"

class Graph {

public:
	Graph(int _vertexCount);

	Edge *addEdge(int _source, int _destination, int _weight);
	Edge *edgeExists(int _source, int _destination);
	void BFS();
	void BFSQueue(int _source, int _destination, vector<bool>& _visited);
	void print();

	~Graph();

private:
	int vertexCount;
	vector<AdjacencyList*> list;
	vector<AdjacencyList*> flow;
};

