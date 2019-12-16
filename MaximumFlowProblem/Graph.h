#pragma once

#include <vector>
#include <queue>

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
	Edge *getEdge(int _source, int _destination);
	void initializeFlow();
	std::vector<int> BFSQueue(int _source, int _destination);
	int FordFulkersonAlgorithm();
	void print();

	~Graph();

private:
	int vertexCount;
	std::vector<AdjacencyList*> list;
	Graph* flowGraph;

};

