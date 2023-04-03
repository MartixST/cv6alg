#include "graph.h"
#include <queue>

Graph::Vertex* Graph::findVertex(int id)
{
	for(auto vertex : vertices)
	{
		if (vertex->id == id)
			return vertex;
	}

	return nullptr;
}

void Graph::insertVertex(int id)
{
	vertices.push_back(new Vertex(id));
}

void Graph::insertVertex(int id, vector<int> neigborIds)
{
	Vertex* newVertex = new Vertex(id);
	vertices.push_back(newVertex);

	for (auto neigborId : neigborIds) {
		Vertex* neighbor = findVertex(neigborId);

		if (neighbor != nullptr)
		{
			newVertex->neighbors.push_back(neighbor);
			if (newVertex->id != neighbor->id)
				neighbor->neighbors.push_back(newVertex);
		}
	}
}

bool Graph::findIdBFS(int id)
{
	Vertex* current = vertices.front();
	queue<Vertex*> queue;

	queue.push(current);
	current->color = 1;

	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();

		current->color = 2;
		if (current->id == id)
			return true;

		for (auto neighbor : current->neighbors)
		{
			if (neighbor->color == 0)
			{
				queue.push(neighbor);
				neighbor->color = 1;
			}
		}
	}

	return false;
}
