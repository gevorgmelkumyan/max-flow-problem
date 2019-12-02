#pragma once

class Edge {

public:
	Edge(int _source, int _destination, int _weight);

private:
	int source;
	int destination;
	int weight;
	Edge* next;

};