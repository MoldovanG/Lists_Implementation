#include "stdafx.h"
#include "Coada_Prioritati.h"
#include "Nod_Prioritate.h"
#include "Node.h"
Coada_Prioritati::Coada_Prioritati()
{

}

Coada_Prioritati::Coada_Prioritati(char c, int prio)
{
	Nod_Prioritate <char> *aux = new Nod_Prioritate <char>; //creez un nou nod dublu si pun prim sa pointeze spre el
	aux->Set_Info(c);
	aux->Set_Prioritate(prio);
	size = 1;
	this->prim = aux;
}

Coada_Prioritati::Coada_Prioritati(const Coada_Prioritati & list)
{
	for (Node <char>*aux = list.prim; aux != NULL; aux = aux->Urmator())//parcurg toate elementele din x si le adaug in lista mea 
	{
		Nod_Prioritate <char>* aux1 = dynamic_cast< Nod_Prioritate<char>*> (aux);
		Push(aux1->Get_Info(), aux1->Get_Prioritate()); //toate alocarile necesare se fac in functia push
	}
}

 Coada_Prioritati::~Coada_Prioritati()
{
	 while (size != 0)
	 {
		 size--;
		 Pop();
	 }

}

 void Coada_Prioritati::Push(char c, int prio)
 {
	 Nod_Prioritate <char>*aux = new Nod_Prioritate <char>;
	 aux->Set_Info(c);
	 aux->Set_Prioritate(prio);
	 Nod_Prioritate<char> *prim1 = dynamic_cast <Nod_Prioritate <char>*>(prim);
	 if (prim1 != NULL)
	 {
		 if (prio >= prim1->Get_Prioritate())//adaug nodul pe prima pozitie
		 {
			 aux->Set_Urm(prim1);
			 prim1->Set_Ant(aux);
			 prim = aux;
		 }
		 else //adaug pe a doua pozitie in lista 
		 {
		    aux->Set_Ant(prim1);
			Nod_Prioritate<char>*aux2 = prim1->Urmator(); //trec cu pointerul pe a doua pozitie
			aux->Set_Urm(aux2);
			if (aux2!=NULL) aux2->Set_Ant(aux); //in fata lui adaug aux deci fac legatura
			prim1->Set_Urm(aux);
		 }
	 }
	 else
	 {
		 prim = aux;
	 }
	 size++;
 }


void Coada_Prioritati::Pop()
{
	Nod_Prioritate<char> maxim;
	Nod_Prioritate<char>* stergere = dynamic_cast<Nod_Prioritate <char>*> (prim);
	prim = prim->Urmator();
	delete stergere;//sterg nodul de pe prima pozitie

	for (Nod_Prioritate<char> *it = dynamic_cast<Nod_Prioritate <char>*>(prim); it != NULL; it = it->Urmator())
	{
		if (maxim.Get_Prioritate() < it->Get_Prioritate()) //caut nodul de prioritate maxima din lista
		{
			maxim.Set_Prioritate(it->Get_Prioritate());
			maxim.Set_Info(it->Get_Info());
		}
	}

	for (Nod_Prioritate<char> *it = dynamic_cast<Nod_Prioritate <char>*>(prim); it != NULL; it = it->Urmator())
		if (it->Get_Prioritate() == maxim.Get_Prioritate()) //sterg nodul din lista si il adaug in fata 
	{
			Nod_Prioritate<char> *aux;
			if (it != prim)
			{
				aux = it->Anterior();
				if (aux != NULL)aux->Set_Urm(it->Urmator());

				aux = it->Urmator();
				if (aux != NULL)aux->Set_Ant(it->Anterior());
				delete it;
			}
			else
			{
				prim = prim->Urmator();
				delete it;
			}
			break;
	}
	Push(maxim.Get_Info(), maxim.Get_Prioritate());
	size--; //fiindca in push se face un size++ nenecesar
}

void Coada_Prioritati::operator=(const Coada_Prioritati & list)
{
	for (int i = 1; i <= size; i++)
		Pop();//eliberez memoria

	for (Node <char>*aux = list.prim; aux != NULL; aux = aux->Urmator())//parcurg toate elementele din x si le adaug in lista mea 
	{
		Nod_Prioritate <char>* aux1 = dynamic_cast< Nod_Prioritate<char>*> (aux);
		Push(aux1->Get_Info(), aux1->Get_Prioritate()); //toate alocarile necesare se fac in functia push
	}

}