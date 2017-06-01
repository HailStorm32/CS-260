#pragma once
/*
Author: geeksforgeeks.org
Modified by: Demetri Van Sickle
IDE: Visual Studio 2015
Program: Graph.h
*/

#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph
{
public:
	Graph(int V);  // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void BFS(int s);  // prints BFS traversal from a given source s
	void DFS(int v);    // DFS traversal of the vertices reachable from v
	
private:
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists

	void DFSUtil(int v, bool visited[]);  // A function used by DFS
};