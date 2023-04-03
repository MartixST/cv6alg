#pragma once
#include <vector>

using namespace std;

class Graph
{
public:
	class Vertex
	{
	public:
		int id;

		vector<Vertex*> neighbors;
		int color = 0;


		Vertex(int id)
		{
			this->id = id;
		}
	};

	vector<Vertex*> vertices;

	Vertex* findVertex(int id);

	void insertVertex(int id);
	void insertVertex(int id, vector<int> neighbors);

	bool findIdBFS(int id);
};