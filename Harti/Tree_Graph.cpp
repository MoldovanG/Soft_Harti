#include "stdafx.h"
#include "Tree_Graph.h"

Tree_Graph::Tree_Graph()
{

}
Tree_Graph::Tree_Graph(const Tree_Graph &G) :Common_Graph(G)
{
	tati = new int[n + 1];
	ponderi=new int[n+1];
	for (int i = 1; i <= n; i++)
	{
		tati[i] = G.tati[i];
		ponderi[i] = G.ponderi[i];;
	}
}
Tree_Graph::~Tree_Graph()
{
	delete []tati;
	delete []ponderi;
}


void Tree_Graph::Read_Graph(istream &in)
{
	int noduri = 0;
	in >> n >> m;
	lista_noduri = new Node[n + 1];
	tati = new int[n + 1];
	ponderi = new int[n + 1];
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
	Initialize_Tati();
}

void Tree_Graph::Print_Graph(ostream &out)
{
	out << "Vectorul de tati asociat arborelui este :\n";
	for (int i = 1; i <= n; i++)
		out << tati[i] << " ";
	cout << "\n";
	out << "Ponderile asociate muchiilor din vectorul de tati sunt:";
		for (int i = 1; i <= n; i++)
			out << ponderi[i] << " ";
		cout << "\n";
}
void Tree_Graph::Calculate_Distance(int *distanta, int x)
{
	if (tati[x] == 0) return;
	else
	{
		distanta[tati[x]] = distanta[x] + ponderi[x];
		Calculate_Distance(distanta, tati[x]);
	}
}

int  Tree_Graph::Distance(int A,int B)
{
	int *distance1, *distance2;// vectori care masoara distanta de la A, repesctiv B catre toate nodurile mai sus de el in arbore
	distance1 = new int[n + 1];
	distance2 = new int[n + 1];

	for (int i = 1; i <= n; i++)
		distance1[i] = distance2[i] = 0;
	Calculate_Distance(distance1, A);
	Calculate_Distance(distance2, B);
	int aux=A;
	while (distance2[aux] == 0 && tati[aux] != 0)
	{
		aux = tati[aux];
	}
	int return_value = distance1[aux] + distance2[aux];
	delete[]distance1;
	delete[]distance2;

	return return_value;
}

void Tree_Graph::DFS(int x, int *viz)
{
	viz[x] = 1;
	int dim = lista_noduri[x].Numar_Vecini();
	lista_noduri[x].Incepere_Parcurgere();
	for (int i = 1; i <= dim; i++)
	{
		pair<int, int> aux = lista_noduri[x].Vecinul_Curent();
		if (viz[aux.first] == 0) {
			tati[aux.first] = x;
			ponderi[aux.first] = aux.second;
			DFS(aux.first, viz);
		}
		lista_noduri[x].Urmatorul_Vecin();
	}

}

void Tree_Graph::Initialize_Tati()
{
	int *viz = new int[n + 1];
	for (int i = 1; i <= n; i++)
		viz[i] = 0;
	tati[1] = 0;
	ponderi[1] = 0;
	DFS(1, viz);

	delete[]viz;
}