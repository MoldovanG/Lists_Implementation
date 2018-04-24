#pragma once

#include "stdafx.h"
#include "Lista_Simplu_Inlantuita.h"
#include "Nod_Dublu.h"
#ifndef LISTA_DUBLU_INLANTUITA_H
#define LISTA_DUBLU_INLANTUITA_H

class Lista_Dublu_Inlantuita : public Lista_Simplu_Inlantuita
{
public:
	Lista_Dublu_Inlantuita();
	Lista_Dublu_Inlantuita(char c);
	Lista_Dublu_Inlantuita(const Lista_Dublu_Inlantuita &);
	~Lista_Dublu_Inlantuita();
	void Push(char); //adauga un caracter in fata listei
	void Pop(); //scot un nod din lista
	void Push_Poz(char, int);
	friend istream &operator >> (istream &in, Lista_Dublu_Inlantuita &x)
	{
		int dim;
		in >> dim;
		int i;
		for (i = 1; i <= dim; i++)
		{
			Nod_Dublu <char> q;
			in >> q;
			x.Push(q.Get_Info());
		}
		return in;
	}

	friend ostream& operator << (ostream &out, Lista_Dublu_Inlantuita &x)
	{
		out << x.Get_size()<<"\n";
		for (Nod_Dublu <char> *aux = dynamic_cast <Nod_Dublu <char>*> (x.prim); aux != NULL; aux = aux->Urmator())
		{  
			out << (*aux)<<"\n";
		}
		return out;
	}
	void operator = (Lista_Dublu_Inlantuita &);
	void operator + (Lista_Dublu_Inlantuita &);

};

#endif // !LISTA_DUBLU_INLANTUITA_H
