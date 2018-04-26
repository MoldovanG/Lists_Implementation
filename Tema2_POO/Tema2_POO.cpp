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


	Lista_Simplu_Inlantuita v[5];
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> v[i];
		fout << v[i] << " \n";
	}
	Coada_Prioritati v1[5];
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> v1[i];
		fout << v1[i] << "\n";
	}
	
	v[1].Push_Poz('x', 3);
	fout << "Elementul de pe poz 3 este :"<<v[1][3]<<"\n";
	fout << "Before split : \n" << v[1] << "\n";
	v[1].Split(3);
	fout << "After split:\n"<<v[1];
	fout << "\n";

	v[1]=(v[1] + v[2]); //acum adunarea returneaza obiect de tip Lista_Dublu_Inlantuita  
	fout << v[1]<<"\n";
	fout << v[2] << "\n";
	v[1] = (v[1] - v[2]); // implementat - la laborator pe liste simplu inlantuita 
	fout << v[1];
	
		return 0;
}

