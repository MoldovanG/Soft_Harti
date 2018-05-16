#pragma once
#include "Common_Graph.h"

#ifndef NORMAL_GRAPH_H
#define NORMAL_GRAPH_H

class Normal_Graph :public Common_Graph
{
public:
	Normal_Graph();
	Normal_Graph(const Normal_Graph &);
	virtual ~Normal_Graph();

	void Print_Graph(ostream &out);
	void Read_Graph(istream &in);
	int Distance(int A, int B);

};
#endif // !NORMAL_GRAPH_H
