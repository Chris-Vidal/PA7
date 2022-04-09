#pragma once
#include "Data.h"

template<class T>
class Node
{
private:
	T data;

	Node* next;
public:
	Node(T = nullptr);

	Node* getNext() const;

	T& getData();

	void setNext(Node<T>* setter);
};

template<class T>
T& Node<T>::getData()
{
	return this->data;
}

template<class T>
Node<T>::Node(T x)
{
	this->data = x;
}

template<class T>
inline Node<T>* Node<T>::getNext() const
{
	return this->next;
}

template<class T>
inline void Node<T>::setNext(Node<T>* setter)
{
	this->next = setter;
}
