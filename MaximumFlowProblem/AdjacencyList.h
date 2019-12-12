#pragma once

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