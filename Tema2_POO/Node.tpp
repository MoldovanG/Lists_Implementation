
#include "stdafx.h"
#include "Node.h"


	template <class T> //constructor de initializare 
	Node <T>::Node()
{

}

	template <class T>
	Node <T>::Node(T c)
{
	info = c;
}
	template<class T>
	Node<T>::Node(const Node &x) //constructor de copiere 
{
	info = x.info;
	urm = x.urm;

}

	template <class T>
	Node <T>::~Node() //totul e alocat static deci nu trebuie sa dezaloc nimic
{

}

	 template<class T>
	 void Node<T>::Set_Info(T x)
 {
	 info = x;

 }

	template<class T>
	void  Node<T>::Set_Urm( Node * nod)
 {
	 urm = nod;
 }

	 template <class T>
	 Node<T> * Node <T>::Urmator() const
{
	 return urm;
}

	 template <class T>
	 T Node <T>::Get_Info()  const
	 {
	 return info;
	}	

	 template <class T>
	void Node<T>::operator=(const Node & x)
	 {
	 info = x.info;
	 urm = x.urm;
	 }
