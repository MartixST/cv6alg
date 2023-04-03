#include <iostream>
#include "graph.h"

using namespace std;



int main()
{
	Graph g;

	g.insertVertex(1);

	vector<int> neighborIds;
	neighborIds.push_back(1);

	g.insertVertex(2, neighborIds);

	neighborIds.clear();
	neighborIds.push_back(1);
	neighborIds.push_back(2);

	g.insertVertex(3, neighborIds);

	neighborIds.clear();
	neighborIds.push_back(1);
	neighborIds.push_back(2);
	neighborIds.push_back(3);

	g.insertVertex(4, neighborIds);

	neighborIds.clear();
	neighborIds.push_back(3);
	neighborIds.push_back(4);

	g.insertVertex(5, neighborIds);

	cout << "Vertex " << (g.findIdBFS(5) ? "" : "NOT") << "found" << endl;

	return 0;
}
