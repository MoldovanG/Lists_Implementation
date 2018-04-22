#pragma once
#include "stdafx.h"
#include "Nod_Dublu.h"

#ifndef NOD_PRIORITATE_H
#define NOD_PRIORITATE_H

template <class T>
class Nod_Prioritate :public Nod_Dublu <T>
{
public:
	Nod_Prioritate();
	Nod_Prioritate(T c,int prio);
	Nod_Prioritate(const Nod_Prioritate &);
	~Nod_Prioritate();

	void operator =(const Nod_Prioritate &);
	int Get_Prioritate();
	void Set_Prioritate(int x);
	friend istream &operator >>(istream &in, Nod_Prioritate<T> &x)
	{
		in >> x.info>>x.prioritate;
		return in;
	}
	friend ostream &operator <<(ostream &out, const Nod_Prioritate<T> &x)
	{
		out << x.info<< x.prioritate;
		return out;
	}

	void Set_Ant(Nod_Prioritate<T> *);
	 void Set_Urm(Nod_Prioritate<T> *);
	 Nod_Prioritate <T> * Urmator();
	 Nod_Prioritate <T> * Anterior();
private:
	int prioritate;
};
#include "Nod_Prioritate.tpp"

#endif