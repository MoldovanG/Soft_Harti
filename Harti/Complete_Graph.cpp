#include "stdafx.h"
#include "Complete_Graph.h"

Complete_Graph::Complete_Graph()
{
}

Complete_Graph::Complete_Graph(const Complete_Graph & G):Common_Graph(G)
{
	mat = new int *[n + 1];//aloc memoria corespunzatoare matricei
	for (int i = 1; i <= n; i++)
		mat[i] = new int[n + 1];

	for (int i = 1; i <= n; i++) // copiez matricea din G in this
		for (int j = 1; j <= n; j++)
			mat[i][j] = G.mat[i][j];

}

Complete_Graph::~Complete_Graph()
{
	for (int i = 0; i < n + 1; i++)
		delete[]mat[i];
	delete[]mat;
}

void Complete_Graph::Print_Graph(ostream & out)
{
	out << "Matricea drumurilor in Graf este : \n";
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				out << mat[i][j] << " ";
			out << "\n";
		}
}

void Complete_Graph::Read_Graph(istream & in)
{
	int noduri = 0;
	in >> n >> m;
	lista_noduri = new Node[n + 1];

	mat = new int *[n + 1];//aloc memoria corespunzatoare matricei
	for (int i = 1; i <= n; i++)
		mat[i] = new int[n + 1];
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mat[i][j] = 0;

	for (int i = 1; i <= m; i++)
	{
		int x1, x2, y1, y2, dist;
		in >> x1 >> y1 >> x2 >> y2;
		if (map[{x1, y1}] == 0)
		{
			noduri++; map[{x1, y1}] = noduri;
		}
		if (map[{x2, y2}] == 0)
		{
			noduri++; map[{x2, y2}] = noduri;
		}
		int nod1, nod2;

		dist = (int)sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));//calculez distanta euclidiana 
		nod1 = map[{x1, y1}];//aflu nodul corespunzator coordonatelor
		nod2 = map[{x2, y2}];

		mat[nod1][nod2] = mat[nod2][nod1] = dist; //construiesc matricea de drumuri

	}
}

int Complete_Graph::Distance(int A, int B)
{
	return mat[A][B];
}
