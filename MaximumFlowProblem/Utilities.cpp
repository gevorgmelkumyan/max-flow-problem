#include "stdafx.h"
#include "Utilities.h"

Edge* Utilities::edgeExists(vector<AdjacencyList*>& list, int _source, int _destination) {
	Edge *edge;

	if (list[_source]) {

		edge = list[_source]->head;
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

vector<AdjacencyList*> Utilities::initAdjacencyListVector(int _vertexCount) {
	vector<AdjacencyList*> list = vector<AdjacencyList *> ();

	for (int i = 0; i < _vertexCount; ++i) {
		AdjacencyList *edge = new AdjacencyList();
		edge->head = nullptr;
		list.push_back(edge);
	}

	return list;
}