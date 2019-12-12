#pragma once

#include <vector>
#include "AdjacencyList.h"

using namespace std;

class Utilities {

public:
	static Edge* edgeExists(vector<AdjacencyList*>& list, int _source, int _destination);
	static vector<AdjacencyList*> initAdjacencyListVector(int _vertexCount);

private:
	Utilities();
	~Utilities();
};

