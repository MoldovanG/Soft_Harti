// Harti.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Regiune.h"
#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int main()
{
	Regiune v[30];
	int n,x,y;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> x >> y; //punctele intre care se calculeaza distanta 
	fin >> v[i];
	fout << v[i].Distanta(x, y)<<"\n";
}
    return 0;
}

