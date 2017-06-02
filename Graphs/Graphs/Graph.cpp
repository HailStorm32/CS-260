/*
Author: geeksforgeeks.org
Modified by: Demetri Van Sickle
IDE: Visual Studio 2015
Program: Graph.cpp
*/

#include "Graph.h"

Graph::Graph(int numOfVertices)
{
	this->numOfVertices = numOfVertices;
	adj = new list<int>[numOfVertices];
}

Graph::~Graph()
{
	delete[] adj;
}

void Graph::addEdge(int currentVertice, int adjacentVertice)
{
	adj[currentVertice].push_back(adjacentVertice); // Add adjacentVertice to currentVertice’s list.
}

void Graph::BFS(int startVertice)
{
	int currentVertice = startVertice;

	// Mark all the vertices as not visited
	bool *visited = new bool[numOfVertices];

	for (int indx = 0; indx < numOfVertices; indx++)
	{
		visited[indx] = false;
	}

	// Create a queue for BFS
	queue<int> queue;

	// Mark the current node as visited and enqueue it
	visited[currentVertice] = true;
	queue.push(currentVertice);

	// 'verticeIterator' will be used to get all adjacent vertices of a vertex
	list<int>::iterator verticeIterator;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		currentVertice = queue.front();
		cout << currentVertice << " ";
		queue.pop();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (verticeIterator = adj[currentVertice].begin(); verticeIterator != adj[currentVertice].end(); ++verticeIterator)
		{
			if (!visited[*verticeIterator])
			{
				visited[*verticeIterator] = true;
				queue.push(*verticeIterator);
			}
		}
	}

	delete[] visited;
}


void Graph::DFS(int startVertice)
{
	// DFS traversal of the vertices reachable from v. 
	// It uses recursive DFSUtil()


	// Mark all the vertices as not visited
	bool *visited = new bool[numOfVertices];

	for (int indx = 0; indx < numOfVertices; indx++)
	{
		visited[indx] = false;
	}

	// Call the recursive helper function to print DFS traversal
	DFSUtil(startVertice, visited);

	delete[] visited;
}

void Graph::DFSUtil(int currentVertice, bool visited[])
{
	// Mark the current node as visited and print it
	visited[currentVertice] = true;
	cout << currentVertice << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator verticeIterator;

	for (verticeIterator = adj[currentVertice].begin(); verticeIterator != adj[currentVertice].end(); ++verticeIterator)
	{
		if (!visited[*verticeIterator])
		{
			DFSUtil(*verticeIterator, visited);
		}
	}
}
