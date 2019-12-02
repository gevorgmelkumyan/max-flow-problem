// MaximumFlowProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"


int main() {
	Graph graph = Graph(4);

	try {
		graph.addEdge(0, 1, 3);
		graph.addEdge(0, 3, 4);
		graph.addEdge(1, 2, 2);
		graph.addEdge(1, 3, 13);
		graph.addEdge(2, 1, 1);
		graph.addEdge(3, 2, 6);
	}
	catch (const std::exception& exception) {
		std::cout << exception.what() << std::endl;
		return 0;
	}

	graph.print();
}

