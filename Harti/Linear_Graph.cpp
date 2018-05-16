#include "stdafx.h"
#include "Linear_Graph.h"
#include <utility>

Linear_Graph::Linear_Graph():Common_Graph()
{
}

Linear_Graph::Linear_Graph(const Linear_Graph & G) : Common_Graph(G)
{
	
	distance = new int[G.n + 1];
	for (int i = 1; i <= n; i++)
		distance[i] = G.distance[i];
	
}


Linear_Graph::~Linear_Graph()
{
	delete[]distance;
}

void Linear_Graph::Print_Graph(ostream & out)
{
	for (int i = 1; i <= n; i++)
	{
		out << "lista nodului : " << i<<"\n";
		lista_noduri[i].Incepere_Parcurgere();
		int dim = lista_noduri[i].Numar_Vecini();
		for (int j = 1; j <= dim; j++)
		{
			pair<int, int>aux = lista_noduri[i].Vecinul_Curent();
			out << aux.first << " " << aux.second << "\n";
			lista_noduri[i].Urmatorul_Vecin();
		}
	}
	
}

void Linear_Graph::Read_Graph(istream &in)
{
	int noduri = 0;
	in >> n >> m;
	lista_noduri = new Node[n + 1];
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
		lista_noduri[nod1].Adauga_Vecin(nod2, dist);
		lista_noduri[nod2].Adauga_Vecin(nod1, dist);

	}
	Initialize_Distance();
}

int Linear_Graph::Distance(int A, int B)
{
	return abs(distance[B] - distance[A]);
}

void Linear_Graph::Initialize_Distance()
{
	delete[] distance;
	distance = new int[n + 1];
	int i;
	for (i = 1; i <= n; i++)
		if (lista_noduri[i].Numar_Vecini() == 1)
		{
			capat = i; break;
		}
	for (i = 1; i <= n; i++)
		distance[i] = 0;
	int tata = 0;
	int nod = capat;
	distance[nod] = 0;
	for (i = 1; i <= n -1; i++)
	{
		pair<int, int> aux;
		int dim = lista_noduri[nod].Numar_Vecini();
		lista_noduri[nod].Incepere_Parcurgere();
		for (int j = 1; j <= dim; j++)
		{
			aux = lista_noduri[nod].Vecinul_Curent();
			if (aux.first != tata) break;
			lista_noduri[nod].Urmatorul_Vecin();

		}
		distance[aux.first] = distance[nod] + aux.second;
		tata = nod;
		nod = aux.first;

	}

}