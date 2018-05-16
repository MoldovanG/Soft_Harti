#pragma once

#ifndef LINEAR_GRAPH_H
#define LINEAR_GRAPH_H


#include "Common_Graph.h"
class Linear_Graph : public Common_Graph
{
public:
	Linear_Graph();
	Linear_Graph(const Linear_Graph &);
	virtual ~Linear_Graph();

	void Print_Graph(ostream &out);
	void Read_Graph( istream &in);
	void Initialize_Distance();
	int Distance(int A, int B);
private:
	int *distance;
	int capat; //unul dintre capetele liniei
};

#endif // !LINEAR_GRAPH_H