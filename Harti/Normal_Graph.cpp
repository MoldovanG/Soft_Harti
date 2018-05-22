#include "stdafx.h"
#include "Normal_Graph.h"
#include <queue>
Normal_Graph::Normal_Graph()
{

}
Normal_Graph::Normal_Graph(const Normal_Graph & G) :Common_Graph(G)
{

}
Normal_Graph::~Normal_Graph()
{

}

void Normal_Graph::Print_Graph(ostream &out)
{
	for (int i = 1; i <= n; i++)
	{
		out << "lista nodului : " << i << "\n";
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

void Normal_Graph::Read_Graph(istream &in)
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
}

int Normal_Graph::Distance(int A, int B)
{
	int *distance = new int[n + 1];
	int *viz = new int[n + 1];
	const int inf = 2000000;
	priority_queue <pair<int, int>> c;// primul element din pereche va fi distanta pana la sursa si al doilea element va fi nodul 
	//voi adauga in coada opusul distantei ca sa transform din max heap in min heap
	
	for (int i = 1; i <= n; i++)
	{
		distance[i] = inf;
		viz[i] = 0;
	}
	distance[A] = 0;
	c.push({ 0,A });
	for (int i = 1; i <= n; i++)
	{   
		pair<int, int> element = c.top();
		c.pop();
		while (viz[element.second] == 1)
		{
			pair<int, int> element = c.top();
			c.pop();

		}

		viz[element.second] = 1;
		
		int val = -element.first;
		int nod = element.second;
		int dim = lista_noduri[nod].Numar_Vecini();
		lista_noduri[nod].Incepere_Parcurgere();
		
		for (int j = 1; j <= dim; j++)
		{
			pair<int, int>aux = lista_noduri[nod].Vecinul_Curent();
			lista_noduri[nod].Urmatorul_Vecin();
			if (aux.second + val < distance[aux.first])
			{
				distance[aux.first] = aux.second + val;
				c.push({ -distance[aux.first],aux.first });
			}
		}

	}

	int return_value = distance[B];
	delete[]distance;
	delete[]viz;

	return return_value;
}