#pragma once

#include "Common_Graph.h"
#ifndef COMPLETE_GRAPH_H
#define	COMPLETE_GRAPH_H


class Complete_Graph :public Common_Graph
{ public:

	Complete_Graph();
	Complete_Graph(const Complete_Graph &);
	virtual ~Complete_Graph();

	void Print_Graph(ostream &out);
	void Read_Graph(istream &in);
	int Distance(int A, int B);
private:
	int **mat;//matrice de drumuri, ca sa afisez distanta in O(1)

};


#endif