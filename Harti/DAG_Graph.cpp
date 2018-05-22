#include"stdafx.h"
#include "DAG_Graph.h"

DAG_Graph::DAG_Graph()
{
}

DAG_Graph::DAG_Graph(const DAG_Graph &G):Common_Graph(G)
{
	sortare_topologica = G.sortare_topologica;
}
DAG_Graph::~DAG_Graph()
{
	
}

void DAG_Graph::Read_Graph(istream & in)
{
	int noduri = 0;
	in >> n >> m;
	lista_noduri = new Node[n + 2];
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

	}
	Sortare_Topologica();
}

void DAG_Graph::Print_Graph(ostream & out)
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

int DAG_Graph::Distance(int A, int B)
{
	int *distance = new int[n + 1];
	const int inf = 2000000000;
	for (int i = 1; i <= n; i++) //initializez distanta fata de sursa cu infinit 
		distance[i] = inf;
	distance[A] = 0;

	for (int i = 0; i < sortare_topologica.size(); i++) //parcurg fiecare nod din sortarea topologica
	{
		int nod = sortare_topologica[i];
		int dim = lista_noduri[nod].Numar_Vecini();
		lista_noduri[nod].Incepere_Parcurgere();
		for (int j = 1; j <= dim; j++) //pentru fiecare vecin al sau actualizez distanta fata de sursa daca e cazul 
		{
			pair <int, int>aux = lista_noduri[nod].Vecinul_Curent();
			if (distance[nod] + aux.second < distance[aux.first])
				distance[aux.first] = distance[nod] + aux.second;
			lista_noduri[nod].Urmatorul_Vecin();
		}
	}
	int return_value = distance[B];
	delete[]distance; //eliberez memoria
	return return_value;
}
void DAG_Graph::DFS(int x, int *viz)
{
	viz[x] = 1;
	int dim = lista_noduri[x].Numar_Vecini();
	lista_noduri[x].Incepere_Parcurgere();
	for (int i = 1; i <= dim; i++)
	{
		pair<int,int> aux = lista_noduri[x].Vecinul_Curent();
		if (viz[aux.first] == 0) DFS(aux.first, viz);
		lista_noduri[x].Urmatorul_Vecin();
	}
	if (x!=n+1) sortare_topologica.push_back(x);
}


void DAG_Graph::Sortare_Topologica()
{
	int *viz = new int[n + 2];
	sortare_topologica.clear();

	for (int i = 1; i <= n; i++)
		viz[i] = 0;

	int grad_interior[Nmax+1] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		int dim = lista_noduri[i].Numar_Vecini();
		lista_noduri[i].Incepere_Parcurgere();
		for (int j = 1; j <= dim; j++)
		{
			pair<int, int >aux = lista_noduri[i].Vecinul_Curent();
			grad_interior[aux.first]++;
		}
	}

	for (int i=1;i<= n;i++)
		if (grad_interior[i] == 0)
		{
			lista_noduri[n+1].Adauga_Vecin(i, 0);
		}
	DFS(n+1,viz);
	std::reverse(sortare_topologica.begin(), sortare_topologica.end());
	delete[]viz;
}
