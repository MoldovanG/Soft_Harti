#pragma once

#ifndef DAG_GRAPH_H
#define DAG_GRAPH_H
#include "Common_Graph.h"
#include <vector>
class DAG_Graph : public Common_Graph
{
public:
	DAG_Graph();
	DAG_Graph(const DAG_Graph &);
	virtual ~DAG_Graph();
	void Read_Graph(istream &in);
	void Print_Graph(ostream &out);
	int Distance(int A, int B);
private:
	vector <int> sortare_topologica;
	void Sortare_Topologica();
	void DFS(int x, int *viz);
};



#endif // !DAG_GRAPH_H
