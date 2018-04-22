#pragma once

#include "stdafx.h"
#include "Lista_Dublu_Inlantuita.h"
#include"Nod_Prioritate.h"
#ifndef  COADA_PRIORITATI_H
#define COADA_PRIORITATI_H

class Coada_Prioritati : public Lista_Dublu_Inlantuita
{ public:
	Coada_Prioritati();
	Coada_Prioritati(char c,int prio);
	Coada_Prioritati(const Coada_Prioritati &);
	~Coada_Prioritati();
	void Push(char c, int prio);
	void Pop();
	void operator = (const Coada_Prioritati &);

	friend istream &operator >> (istream &in, Coada_Prioritati &x)
	{
		int dim;
		in >> dim;
		int i;
		for (i = 1; i <= dim; i++)
		{
			Nod_Prioritate <char> q;
			in >> q;
			x.Push(q.Get_Info(),q.Get_Prioritate());
		}
		return in;
	}

	friend ostream& operator << (ostream &out, Coada_Prioritati &x)
	{
		out << x.Get_size() << "\n";
		for (Nod_Prioritate <char> *aux = dynamic_cast <Nod_Prioritate <char>*> (x.prim); aux != NULL; aux = aux->Urmator())
		{
			out << (*aux) << "\n";
		}
		return out;
	}


};

#endif // ! COADA_PRIORITATI_H
