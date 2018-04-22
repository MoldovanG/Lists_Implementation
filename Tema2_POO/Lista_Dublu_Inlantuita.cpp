#include "stdafx.h"
#include "Lista_Dublu_Inlantuita.h"
#include "Node.h"
#include "Nod_Dublu.h"
Lista_Dublu_Inlantuita::Lista_Dublu_Inlantuita():Lista_Simplu_Inlantuita()
{

}

Lista_Dublu_Inlantuita::Lista_Dublu_Inlantuita(char c)
{
	Nod_Dublu <char> *aux = new Nod_Dublu <char>; //creez un nou nod dublu si pun prim sa pointeze spre el
	aux->Set_Info(c);
	size = 1;
	this->prim = aux;
}

Lista_Dublu_Inlantuita::Lista_Dublu_Inlantuita(const Lista_Dublu_Inlantuita & x)
{
	
	for (Node <char>*aux = x.prim; aux != NULL; aux = aux->Urmator())//parcurg toate elementele din x si le adaug in lista mea 
		Push(aux->Get_Info()); //toate alocarile necesare se fac in functia push

}

Lista_Dublu_Inlantuita::~Lista_Dublu_Inlantuita()
{
	while (size != 0)
	{
		size--;
		Pop();
	}
}


void Lista_Dublu_Inlantuita::Push(char c)
{
	Nod_Dublu <char> *aux = new Nod_Dublu <char>;
	Nod_Dublu<char> *prim1 = dynamic_cast <Nod_Dublu<char> *> (prim); //preiau un nod dublu din pointerul prim
	aux->Set_Info(c);
	aux->Set_Urm(prim1);
if (prim1!=NULL) prim1->Set_Ant(aux);
	prim = aux;

	size++;
}
void Lista_Dublu_Inlantuita::Pop()
{
	Nod_Dublu<char>*prim1 = dynamic_cast<Nod_Dublu <char>*> (prim);
	if (prim!=NULL)
	prim = prim->Urmator();//mut prim pe pozitie urmatoare in lista
	else prim = NULL;

	size--;
	delete prim1;

}

void Lista_Dublu_Inlantuita::operator = (Lista_Dublu_Inlantuita & list)
{
	for (int i = 1; i <= size; i++)
		Pop();//eliberez memoria listei curente 
	size = 0;

	for (Node <char>*aux = list.prim; aux != NULL; aux = aux->Urmator())//parcurg toate elementele din x si le adaug in lista mea 
	{
		char caracter = aux->Get_Info();
		Push(caracter); //toate alocarile necesare se fac in functia push
	}
}
