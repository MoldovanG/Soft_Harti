#pragma once
// *****_____IMPORTANT____****
///DESI CLASA SE NUMESTE COADA, NU SE COMPORTA CA O COADA CI CA O LISTA SIMPLU INLANTUITA. SE ADAUGA IN FATA SI SE SCOATE TOT DIN FATA 


#ifndef COADA_H
#define COADA_H
#include "stdafx.h"
#include <utility>
using namespace std;

template <class T>
class Coada
{
public :
	Coada(); //Initialize constructor 
	Coada(const Coada&);// Copy constructor
	~Coada(); //Destructor

	void Push(T,T);//operatie de adaugare in fata
	void Pop(); //operatie de eliminare a nodului din fata
	pair<T,T> Front(); //returneaza informatia din primul nod
	int Find(T);// returneaza 1 daca elementul se gaseste in lista, -1 altfel
	int GetSize() const;
	void Set_Cursor_First();//seteaza cursorul la inceputul listei
	pair<T,T> Get_Current(); //returneaza elementul retinut la pozitia curenta a cursorului
	void Next();//muta cursorul cu o pozitie in fata
	
	bool operator == ( Coada <T>&);
	bool operator < (const Coada <T>&) const;
	bool operator != (Coada <T> &);

private:
	struct nod 
	{
		T info,pondere;
		nod *urm;
	}*first,*cursor;
	int size;

};

#endif