#pragma once
#include "Common_Graph.h"
#ifndef TREE_GRAPH_H
#define TREE_GRAPH_H

class Tree_Graph :public Common_Graph
{
public:
	Tree_Graph();
	Tree_Graph(const Tree_Graph &);
	virtual ~Tree_Graph();

	void Print_Graph(ostream &out);
	void Read_Graph(istream &in);
	int Distance(int A, int B);
private :
	int *tati;//vector de tati
	int *ponderi;//costul muchiei de la nod la tata
	void Initialize_Tati();
	void DFS(int x, int *viz);
	void Calculate_Distance(int *,int);
	
    
};
#endif // !TREE_GRAPH_H
