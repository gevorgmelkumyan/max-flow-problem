#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <exception>

Edge::Edge(int _source, int _destination, int _weight) {
	this->source = _source;
	this->destination = _destination;
	this->weight = _weight;
	this->next = nullptr;
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

Edge *Graph::addEdge(int _source, int _destination, int _weight) {

	if (_source >= this->vertexCount || _destination >= this->vertexCount) {
		throw std::exception("There is no such vertices.");
	}

	Edge *edge;
	if (edge = this->edgeExists(_source, _destination)) {
		edge->weight = _weight;
	} else {
		edge = new Edge(_source, _destination, _weight);
		edge->next = this->list[_source]->head;
		this->list[_source]->head = edge;
	}
	
	return edge;
}

void Graph::BFS() {

	std::vector<bool> visited = std::vector<bool>(this->vertexCount);

	for (int i = 0; i < this->vertexCount; ++i) {
		visited[i] = false;
	}

	int source = 0;
	int destination = this->vertexCount - 1;

	this->BFSQueue(source, destination, visited);
}

void Graph::BFSQueue(int _source, int _destination, std::vector<bool>& _visited) {

	int currentIndex;
	std::queue<int> queue;

	_visited[_source] = true;
	queue.push(_source);

	while (!queue.empty()) {
		currentIndex = queue.front();
		queue.pop();

		Edge* head = this->list[currentIndex]->head;

		while (head != nullptr) {
			if (!_visited[head->destination]) {
				std::cout << head->destination << std::endl;
				_visited[head->destination] = true;
				queue.push(head->destination);
			}

			head = head->next;
		}
	}
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

Edge *Graph::edgeExists(int _source, int _destination) {

	Edge *edge;

	if (this->list[_source]) {

		edge = this->list[_source]->head;
		while (edge != nullptr) {
			if (edge->destination == _destination) {
				return edge;
			}

			edge = edge->next;
		}

		return nullptr;
	}

	return nullptr;
}


Graph::~Graph() {
	for (int i = 0; i < this->vertexCount; ++i) {
		delete this->list[i];
	}
}
