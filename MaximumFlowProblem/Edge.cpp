#include "stdafx.h"
#include "Edge.h"

Edge::Edge(int _source, int _destination, int _weight) {
	source = _source;
	destination = _destination;
	weight = _weight;
}

void Edge::setNext(Edge *_next) {
	this->next = _next;
}

Edge *Edge::getNext() const {
	return this->next;
}

int Edge::getSource() {
	return this->source;
}

int Edge::getDestination() {
	return this->destination;
}

int Edge::getWeight() {
	return this->weight;
}