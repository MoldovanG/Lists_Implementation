#include "stdafx.h"
#include "Nod_Prioritate.h"


template <class T>
Nod_Prioritate<T>::Nod_Prioritate ()
{
}

template <class T>
Nod_Prioritate<T>::Nod_Prioritate (T c,int prio):Nod_Dublu<T>(c)
{
prioritate=prio;
}

template <class T>
Nod_Prioritate<T>::Nod_Prioritate (const Nod_Prioritate & x):Nod_Dublu<T>(x)
{
prioritate=x.prioritate;
}


template <class T>
Nod_Prioritate<T>::~Nod_Prioritate ()
{
}

template <class T>
void Nod_Prioritate<T>::operator = (const Nod_Prioritate & x)
{
anterior=x.anterior;
urmator=x.urmator;
info=x.info;
prioritate=x.prioritate;
}

template <class T>
int Nod_Prioritate<T>::Get_Prioritate ()
{
return prioritate;
}

template <class T>
void Nod_Prioritate<T>::Set_Prioritate(int x)
{
prioritate=x;
}

template <class T>
void Nod_Prioritate<T>::Set_Urm ( Nod_Prioritate *x)
{
 this->urm=x;
}

template <class T>
void Nod_Prioritate <T>::Set_Ant( Nod_Prioritate *x)
{
this->anterior=x;
}

template <class T>
	Nod_Prioritate <T>* Nod_Prioritate<T>::Urmator ()
{
Nod_Prioritate *w;
w=dynamic_cast <Nod_Prioritate <T>*> (this->urm);
return w;
}


	template <class T>
	Nod_Prioritate <T>* Nod_Prioritate<T>::Anterior()
{
	Nod_Prioritate *w;
	Node <T> *aux=this->anterior;
	w=dynamic_cast <Nod_Prioritate <T> *> (aux);
	
	return w;
}
