// MaximumFlowProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"

int main() {

	Graph graph = Graph(6);
	graph.initializeFlow();

	try {
		graph.addEdge(0, 1, 16);
		graph.addEdge(1, 3, 12);
		graph.addEdge(3, 5, 20);
		graph.addEdge(0, 2, 13);
		graph.addEdge(2, 4, 14);
		graph.addEdge(4, 5, 4);
		graph.addEdge(2, 1, 4);
		graph.addEdge(3, 2, 9);
		graph.addEdge(4, 3, 7);
	}
	catch (const exception& exception) {
		cout << exception.what() << endl;
		return 0;
	}

	int maxFlow = graph.FordFulkersonAlgorithm();

	graph.print();

	cout << "maxFlow=" << maxFlow << endl;
}

