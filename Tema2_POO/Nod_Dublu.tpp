
#include "stdafx.h"
#include "Nod_Dublu.h"
#include "Node.h"

template <class T>
Nod_Dublu<T>::Nod_Dublu()
{

}

template <class T>
Nod_Dublu<T>::Nod_Dublu(T c) :Node<T>(c)
{

}

template <class T>
Nod_Dublu<T>::Nod_Dublu(const Nod_Dublu & x) : Node<T>(x)
{
	anterior = x.anterior;
}

template <class T>
Nod_Dublu<T>::~Nod_Dublu()
{

}
template <class T>
void Nod_Dublu<T>::operator= (const Nod_Dublu & x)
{
	anterior = x.anterior;
	info = x.info;
	urm = x.urm;
}
template <class T>
void Nod_Dublu<T>::Set_Urm ( Nod_Dublu *x)
{
 this->urm=x;
}

template <class T>
void Nod_Dublu <T>::Set_Ant( Nod_Dublu *x)
{
this->anterior=x;
}

	template <class T>
	Nod_Dublu <T>* Nod_Dublu<T>::Urmator ()
{
Nod_Dublu *w;
w=dynamic_cast <Nod_Dublu <T>*> (this->urm);
return w;
}


	template <class T>
	Nod_Dublu <T>* Nod_Dublu<T>::Anterior()
{
	Nod_Dublu *w;
	
	w=dynamic_cast <Nod_Dublu<T> *> (anterior);
	
	return w;
}