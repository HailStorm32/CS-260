#pragma once
/*
Author: geeksforgeeks.org
Modified by: Demetri Van Sickle
IDE: Visual Studio 2015
Program: Graph.h
*/

#include<iostream>
#include <list>
#include <queue>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph
{
public:
	Graph(int numOfVertices);  // Constructor
	
	~Graph();

	void addEdge(int currentVertice, int adjacentVertice); // function to add an edge to graph

	void BFS(int startVertice);  // prints BFS traversal from a given source startVertice

	void DFS(int startVertice);    // DFS traversal of the vertices reachable from startVertice

	
private:
	int numOfVertices;  
	list<int> *adj;    // Pointer to an array containing adjacency lists

	void DFSUtil(int currentVertice, bool visited[]);  // A function used by DFS
};