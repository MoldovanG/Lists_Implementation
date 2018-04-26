#pragma once
#include "stdafx.h"
#include <iostream>
#ifndef NODE_H
#define NODE_H 

using namespace std;

template <class T>
class Node
{
public:
	Node();
	Node(T);
	Node(const Node &);
	virtual ~Node();
	void Set_Info(T);
	virtual void Set_Urm(Node *);
	Node * Urmator() const ;
	T Get_Info() const ;

	//virtual Get_Prioritate() = 0;

	virtual void operator =(const Node &);
	
	friend istream &operator >>(istream &in, Node <T> &x)
	{
		in >> x.info;
		return in;
	}
	friend ostream &operator <<(ostream &out, const Node <T> &x)
	{
		out << x.info;
		return out;
	}

protected :
	T info;
	Node <T>*urm;

};

#include "Node.tpp"
#endif // !"NODE.H"
