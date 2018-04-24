#pragma once
#include "stdafx.h"

#ifndef LISTA_SIMPLU_INLANTUITA_H
#define LISTA_SIMPLU_INLANTUITA_H
#include "Node.h"

class Lista_Simplu_Inlantuita
{
public:
	Lista_Simplu_Inlantuita();
	Lista_Simplu_Inlantuita(char c);
	Lista_Simplu_Inlantuita(const Lista_Simplu_Inlantuita &);
	~Lista_Simplu_Inlantuita();
	virtual void Push(char ); //adauga un caracter in fata listei
	virtual void Push_Poz(char, int);
	virtual char Front();
	virtual void Pop();
	virtual int Get_size();
	friend istream &operator >> (istream &in, Lista_Simplu_Inlantuita &x)
	{
		int dim;
		in >> dim;
		//x.Set_size(dim);
		int i;
		for (i = 1; i <= dim; i++)
		{
			Node <char> q;
			in >> q;
			x.Push(q.Get_Info());
		}
		return in;
	}

	friend ostream& operator << (ostream &out, Lista_Simplu_Inlantuita &x)
	{
		out << x.Get_size()<<"\n";
		for (Node <char> *aux=x.prim;aux!=NULL;aux=aux->Urmator())
		{
			out << (*aux)<<" ";
		}
		return out;
	}

	void operator = (Lista_Simplu_Inlantuita & );
	void operator +(Lista_Simplu_Inlantuita &);
	Node <char> & operator [] (int i);
	Node <char> * Split(int i); // imparte lista in 2 incepand cu pozitia i, returneaza pointerul de inceput celei de a doua liste 
	int Find_Element(char c); // cauta un element in lista si returneaza prima pozitie pe care apare 
protected:
	virtual void Set_size(int x);
	Node <char> *prim;
	int size;

};

#endif // !LISTA_SIMPLU_INLANTUITA_H
