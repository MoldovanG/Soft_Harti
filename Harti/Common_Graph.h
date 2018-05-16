#pragma once

#ifndef COMMON_GRAPH_H
#define COMMON_GRAPH_H
#define Nmax 3500
#include "Node.h"
#include <iostream>
#include <map>

class Common_Graph
{
public:
	Common_Graph();
	Common_Graph(const Common_Graph &);
	virtual ~Common_Graph();
	virtual int  Distance(int A, int B)=0 ;
	virtual void Read_Graph(istream &in) = 0;
	virtual void Print_Graph(ostream &out) = 0;
	friend istream &operator >> (istream &in,Common_Graph &x)
	{
		x.Read_Graph(in);
		return in;
	}
	friend ostream &operator << (ostream &out, Common_Graph &x)
	{
		x.Print_Graph(out);
		return out;
	}
protected:
	int n;//numarul de noduri
	int m; // numarul de muchii
	Node *lista_noduri;
	map<pair<int, int>, int> map; //asa stiu ca perechea de coordonate (x,y) ii corespunde nodul map[{x,y}]

};

#endif // !COMMON_GRAPH_H
