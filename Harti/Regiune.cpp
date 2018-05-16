
#include "stdafx.h"
#include "Regiune.h"

Regiune::Regiune()
{
	G = NULL;
}

Regiune::~Regiune()
{
 if (G!=NULL)	delete G;
}

int Regiune::Distanta(int A, int B)
{
	return G->Distance(A, B);
}

