#pragma once

#include <vector>

struct Edge {
	int source;
	int destination;
	int weight;
	Edge* next;

	Edge(int _source, int _destination, int _weight);
};

struct AdjacencyList {
	Edge* head;
};

class Graph {

public:
	Graph(int _vertexCount);

	Edge *addEdge(int _source, int _destination, int _weight);
	Edge *edgeExists(int _source, int _destination);
	void print();

	~Graph();

private:
	int vertexCount;
	std::vector<AdjacencyList*> list;

};

