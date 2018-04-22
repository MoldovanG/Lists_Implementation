
#include "stdafx.h"
#include "Node.h"
#include "Lista_Simplu_Inlantuita.h"

Lista_Simplu_Inlantuita::Lista_Simplu_Inlantuita()
{
	size = 0;
	prim = NULL;
}
Lista_Simplu_Inlantuita::Lista_Simplu_Inlantuita(char c)
{
	Node <char> *q = new Node <char>;
	q->Set_Info(c);

	q->Set_Urm(prim);
	
	prim = q;//creez un nod si il pun ca primul nod din lista
	size = 1;
}
Lista_Simplu_Inlantuita::Lista_Simplu_Inlantuita(const Lista_Simplu_Inlantuita & list)
{
	size = 0;
	for (Node <char> *q = list.prim; q != NULL;q=q->Urmator()) //copiez fiecare element din lista parametru in cea curenta
	{   
		char aux = q->Get_Info();
		Push(aux);//marimea listei se actualizeaza automat in push

	}
}

Lista_Simplu_Inlantuita::~Lista_Simplu_Inlantuita()
{
	while (prim != NULL)
		Pop();
}

void Lista_Simplu_Inlantuita::Push(char c) //adauga un nod in fata listei 
{
	Node <char> *q = new Node<char>;
	q->Set_Info(c);
	q->Set_Urm(prim);
	prim = q;
	size++;
	
}


char Lista_Simplu_Inlantuita::Front()
{
	return prim->Get_Info();
}

void Lista_Simplu_Inlantuita::Pop()
{
	size--;
	if (prim != NULL)
	{
		Node <char> *q = prim;
		prim = prim->Urmator();
		delete q;
	}

}

int Lista_Simplu_Inlantuita::Get_size()
{
	return size;
}

void Lista_Simplu_Inlantuita::Set_size(int x)
{
	size = x;
}

void Lista_Simplu_Inlantuita::operator= (Lista_Simplu_Inlantuita & list)
{
	
	for (int i = 1; i <= size; i++) Pop();/* Eliberez memoria din lista curenta*/
	size = 0;
	for (Node <char> *q = list.prim; q != NULL; q = q->Urmator()) //copiez fiecare element din lista parametru in cea curenta
	{
		char aux = q->Get_Info();
		Push(aux);

	}

}