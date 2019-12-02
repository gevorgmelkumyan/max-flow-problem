#include "stdafx.h"
#include "Graph.h"
#include <iostream>

Edge::Edge(int _source, int _destination, int _weight) {
	this->source = _source;
	this->destination = _destination;
	this->weight = _weight;
}

Graph::Graph(int _vertexCount) {
	this->vertexCount = _vertexCount;
	this->list = std::vector<AdjacencyList *> ();

	for (int i = 0; i < this->vertexCount; ++i) {
		AdjacencyList *edge = new AdjacencyList();
		edge->head = nullptr;
		this->list.push_back(edge);
	}
}

Edge *Graph::addEdge(int _source, int _destination, int _weight) const {
	Edge *edge = new Edge(_source, _destination, _weight);
	edge->next = this->list[_source]->head;
	this->list[_source]->head = edge;

	return edge;
}

void Graph::print() {
	Edge *edge;
	for (int i = 0; i < this->vertexCount; ++i) {
		edge = this->list[i]->head;
		std::cout << i << " ---> [";
		while (edge != nullptr) {
			std::cout << "(" << edge->destination << ", " << edge->weight << ")";

			if (edge->next != nullptr) {
				std::cout << ", ";
			}
			else {
				std::cout << "]" << std::endl;
			}

			edge = edge->next;
		}
	}
}


Graph::~Graph() {
	for (int i = 0; i < this->vertexCount; ++i) {
		delete this->list[i];
	}
}
