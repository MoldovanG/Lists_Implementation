// Tema2_POO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Nod_Dublu.h"
#include "Node.h"
#include "Nod_Prioritate.h"
#include "Lista_Simplu_Inlantuita.h"
#include "Lista_Dublu_Inlantuita.h"
#include "Coada_Prioritati.h"
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

int main()
{
	
	
	Lista_Simplu_Inlantuita x,y;
	fin >> x;
	fin >> y;
	x + y;
	x.Push_Poz('y', 3);
	x.Split(4);
	fout << x<<"\n";
	fout << x[3];
	fout << x.Find_Element('y');

		return 0;
}

