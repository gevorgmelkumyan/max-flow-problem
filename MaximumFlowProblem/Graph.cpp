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
	this->list = Utilities::initAdjacencyListVector(this->vertexCount);
	this->flow = Utilities::initAdjacencyListVector(this->vertexCount);
}

Edge *Graph::addEdge(int _source, int _destination, int _weight) {

	if (_source >= this->vertexCount || _destination >= this->vertexCount) {
		throw exception("There is no such vertices.");
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

	vector<bool> visited = vector<bool>(this->vertexCount);

	for (int i = 0; i < this->vertexCount; ++i) {
		visited[i] = false;
	}

	int source = 0;
	int destination = this->vertexCount - 1;

	this->BFSQueue(source, destination, visited);
}

void Graph::BFSQueue(int _source, int _destination, vector<bool>& _visited) {

	int currentIndex;
	queue<int> queue;

	_visited[_source] = true;
	queue.push(_source);

	while (!queue.empty()) {
		currentIndex = queue.front();
		queue.pop();

		Edge* head = this->list[currentIndex]->head;

		while (head != nullptr) {
			if (!_visited[head->destination]) {
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
		cout << i << " ---> [";
		while (edge != nullptr) {
			cout << "(" << edge->destination << ", " << edge->weight << ")";

			if (edge->next != nullptr) {
				cout << ", ";
			}
			else {
				cout << "]" << endl;
			}

			edge = edge->next;
		}
	}
}

Edge *Graph::edgeExists(int _source, int _destination) {
	return Utilities::edgeExists(this->list, _source, _destination);
}


Graph::~Graph() {
	for (int i = 0; i < this->vertexCount; ++i) {
		delete this->list[i];
	}
}
