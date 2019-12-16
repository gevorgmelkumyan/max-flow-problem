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
	this->list = vector<AdjacencyList*> ();

	for (int i = 0; i < this->vertexCount; ++i) {
		AdjacencyList* edge = new AdjacencyList();
		edge->head = nullptr;
		this->list.push_back(edge);
	}
}

Edge* Graph::addEdge(int _source, int _destination, int _weight) {

	if (_source >= this->vertexCount || _destination >= this->vertexCount) {
		throw exception("There is no such vertices.");
	}

	if (this->flowGraph != nullptr) {
		this->flowGraph->addEdge(_source, _destination, 0);
	}

	Edge* edge;
	if (edge = this->edgeExists(_source, _destination)) {
		edge->weight = _weight;
	} else {
		edge = new Edge(_source, _destination, _weight);
		edge->next = this->list[_source]->head;
		this->list[_source]->head = edge;
	}
	
	return edge;
}

void Graph::initializeFlow() {
	this->flowGraph = new Graph(this->vertexCount);
	this->flowGraph->flowGraph = nullptr;
}

int Graph::FordFulkersonAlgorithm() {

	int source = 0;
	int destination = this->vertexCount - 1;
	int maxFlow = 0;

	vector<int> parent;

	bool pathExists = true;

	while (true) {
		parent = this->BFSQueue(source, destination);
		pathExists = (parent[destination] != -1);

		if (!pathExists) {
			break;
		}

		int pathFlow = INT_MAX;

		int u;
		int v;

		for (v = destination; v != source; v = parent[v]) {
			u = parent[v];
			pathFlow = min(pathFlow, this->getEdge(u, v)->weight - this->flowGraph->getEdge(u, v)->weight);
		}

		for (v = destination; v != source; v = parent[v]) {
			u = parent[v];
			this->flowGraph->addEdge(u, v, pathFlow);
		}

		maxFlow += pathFlow;
	}

	return maxFlow;
}

vector<int> Graph::BFSQueue(int _source, int _destination) {

	int currentIndex;
	queue<int> queue;
	vector<bool> visited = vector<bool>(this->vertexCount, false);
	vector<int> parent = vector<int>(this->vertexCount, -1);

	visited[_source] = true;
	queue.push(_source);

	while (!queue.empty()) {
		currentIndex = queue.front();
		queue.pop();

		Edge* head = this->list[currentIndex]->head;

		while (head != nullptr) {
			if (!visited[head->destination] && this->flowGraph->getEdge(head->source, head->destination)->weight < head->weight) {
				visited[head->destination] = true;
				parent[head->destination] = head->source;
				queue.push(head->destination);
			}

			head = head->next;
		}
	}

	return parent;
}

void Graph::print() {
	Edge* edge;
	for (int i = 0; i < this->vertexCount; ++i) {
		edge = this->list[i]->head;
		cout << i << " ---> [";

		if (edge == nullptr) {
			cout << "]" << endl;
			continue;
		}

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

Edge* Graph::edgeExists(int _source, int _destination) {

	Edge* edge;

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

Edge* Graph::getEdge(int _source, int _destination) {
	return this->edgeExists(_source, _destination);
}


Graph::~Graph() {
	for (int i = 0; i < this->vertexCount; ++i) {
		delete this->list[i];
	}
}
