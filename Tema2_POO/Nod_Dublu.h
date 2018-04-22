#pragma once
#include "stdafx.h"
#include "Node.h"

#ifndef NOD_DUBLU_H
#define NOD_DUBLU_H
template <class T>
class Nod_Dublu :public Node <T>
{
public:
	Nod_Dublu();

	Nod_Dublu(T c);
	
	Nod_Dublu(const Nod_Dublu & c);
	
	~Nod_Dublu();

	void operator = (const Nod_Dublu &);

	friend istream &operator >>(istream &in, Nod_Dublu <T> &x)
	{
		in >> x.info;
		return in;
	}
	friend ostream &operator <<(ostream &out, const Nod_Dublu <T> &x)
	{
		out << x.info;
		return out;
	}
	virtual void Set_Ant( Nod_Dublu<T> *);
	virtual void Set_Urm( Nod_Dublu<T> *);
	Nod_Dublu <T> * Urmator();
	Nod_Dublu <T> * Anterior();

protected:
	Node <T> * anterior;

};



#include "Nod_Dublu.tpp"
#endif
