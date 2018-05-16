#include "stdafx.h"
#include "Common_Graph.h"

Common_Graph::Common_Graph()
{
	n = m = 0;
}

Common_Graph::Common_Graph(const Common_Graph & x)
{
	n = x.n;
	m = x.m;
	Node *aux; //copiez lista nodurile lui x in aux
	aux = new Node[n + 1];
	for (int i = 1; i <= n; i++) //parcurg fiecare lista a fiecarui nod din lista de noduri al lui x
	{
		x.lista_noduri[i].Incepere_Parcurgere();
		int dimensiune = x.lista_noduri[i].Numar_Vecini();
		for (int j = 1; j <= dimensiune; j++) //preiau fiecare element si il adaug pe poz corespunzatoare in aux
		{
			pair<int,int> element = x.lista_noduri[i].Vecinul_Curent();
			x.lista_noduri[i].Urmatorul_Vecin();
			aux[i].Adauga_Vecin(element.first,element.second);
		}
	}
	lista_noduri = aux; // atribui listei obiectului curent, lista tocmai creata
}

Common_Graph::~Common_Graph()
{
	delete[]lista_noduri;
	

}

