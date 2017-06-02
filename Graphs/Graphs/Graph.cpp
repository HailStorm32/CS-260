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

	adjMatrix = new int*[numOfVertices];

	for (int i = 0; i < numOfVertices; i++)
	{
		adjMatrix[i] = new int[numOfVertices];
		for (int j = 0; j < numOfVertices; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph()
{
	delete[] adjMatrix;
}

void Graph::addEdge(int currentVertice, int adjacentVertice)
{
	const int FROM = currentVertice; //row
	const int TO = adjacentVertice; //col

	adjMatrix[FROM][TO] = 1; // Add adjacentVertice to currentVertice’s list.
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


	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		currentVertice = queue.front();
		cout << currentVertice << " ";
		queue.pop();

		// Get all adjacent vertices of the dequeued vertex currentVertice
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (int indx = 0; indx < numOfVertices; ++indx)
		{
			if(adjMatrix[currentVertice][indx] == 0)
			{
				continue;
			}
			else if (!visited[indx])
			{
				visited[indx] = true;
				queue.push(indx);
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

	for (int indx = 0; indx < numOfVertices; ++indx)
	{
		if (adjMatrix[currentVertice][indx] == 0)
		{
			continue;
		}
		else if (!visited[indx])
		{
			DFSUtil(indx, visited);
		}
	}
}
