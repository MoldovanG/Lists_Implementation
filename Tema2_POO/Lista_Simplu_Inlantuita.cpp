
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
	int it = 1;
	while (prim != NULL && it <= size)
	{Pop(); it++;
	}
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

void Lista_Simplu_Inlantuita::operator= (const Lista_Simplu_Inlantuita & list)
{
	
	for (int i = 1; i <= size&& prim!=NULL; i++) Pop();/* Eliberez memoria din lista curenta*/
	size = 0;
	prim = NULL;
	int it = 1;
	for (Node <char> *q = list.prim; it<=list.size && q != NULL; q = q->Urmator()) //copiez fiecare element din lista parametru in cea curenta
	{
		it++;
			char aux = q->Get_Info();
			Push(aux);
		
	}

}

Lista_Simplu_Inlantuita Lista_Simplu_Inlantuita::operator+(Lista_Simplu_Inlantuita & list)
{
	Lista_Simplu_Inlantuita lista_aux(*this);

	Node <char> *aux = list.prim;
	while (aux != NULL)//iau toate elementele din list si le adaug in lista curent, rezultatul va fi cele 2 liste concatenate
	{lista_aux.Push(aux->Get_Info());
	aux = aux->Urmator();
	}
	*this = lista_aux;
	return (*this);
}

Node <char> & Lista_Simplu_Inlantuita:: operator [] (int i)
{
	Node <char> *aux = prim;
	int cont = 1;
	while (aux != NULL && cont < i)
	{
		aux = aux->Urmator();
		cont++;

	}
	return *aux;
}

void Lista_Simplu_Inlantuita::Push_Poz(char c, int poz)
{

	Node <char> &aux = (*this)[poz];
	Node <char> &aux1 = (*this)[poz - 1];
	Node <char> *nod_nou = new Node <char>;
	nod_nou->Set_Info(c);
	nod_nou->Set_Urm(&aux);
	aux1.Set_Urm(nod_nou);
	
}

Node <char> * Lista_Simplu_Inlantuita::Split(int i)
{		
	if (i >= size) throw "Rupere imposibile, pozitie necorespunzatoare";
	Node <char> &aux = (*this)[i];
	Node <char> &aux1 = (*this)[i + 1];
	aux.Set_Urm(NULL);
	this->size = i;
	return &aux1;
}

int  Lista_Simplu_Inlantuita::Find_Element(char c) //cauta un element cu informatia c  in el si returneaza prima pozitie valida ,-1 daca nu e gasit 
{
	int cnt = 0;
	for (Node <char> *aux = prim; aux != NULL; aux = aux->Urmator())
	{
		cnt++;
		if (aux->Get_Info() == c) return cnt;
	}
	return -1;

}

Lista_Simplu_Inlantuita  Lista_Simplu_Inlantuita:: operator- (Lista_Simplu_Inlantuita & list)
{
	Lista_Simplu_Inlantuita aux_list;
     
	for (Node <char> *aux = prim; aux != NULL; aux = aux->Urmator())
	{
		if (list.Find_Element(aux->Get_Info()) == -1) //nu se afla in lista pe care vreau sa o scad 
			aux_list.Push(aux->Get_Info());
	}
	
	return aux_list;
}