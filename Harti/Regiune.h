#pragma once
#include "Common_Graph_Factory.h"
#ifndef REGIUNE_H
#define REGIUNE_H


class Regiune
{public:
	Regiune();
	~Regiune();
	friend istream & operator >> (istream & in, Regiune & H)
	{
		char s[256];
		in.get();
		in.getline(s, 256);
		H.G = Common_Graph_Factory::Create_Common_Graph(s);

		in >> *(H.G);
		return in;
	}
	int Distanta(int A, int B);
private:
	Common_Graph * G;
};
#endif // !REGIUNE_H
