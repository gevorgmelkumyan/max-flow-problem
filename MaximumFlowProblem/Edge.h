#pragma once

class Edge {

public:
	Edge(int _source, int _destination, int _weight);
	void setNext(Edge *_next);

	Edge *getNext() const;
	int getSource();
	int getDestination();
	int getWeight();

private:
	int source;
	int destination;
	int weight;
	Edge* next;

};