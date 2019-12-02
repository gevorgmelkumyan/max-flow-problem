#pragma once

#include <vector>
#include "Edge.h"

struct AdjacencyList {
	Edge* head;
};

class Graph {

public:
	Graph(int _vertexCount);

	Edge* addEdge(int _source, int _destination, int _weight) const;
	void print();

	~Graph();

private:
	int vertexCount;
	std::vector<AdjacencyList*> list;

};

