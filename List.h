#pragma once

#include "Node.h"
#include "Data.h"

template<class T>
class List
{
private:
	Node<T>* pList; // turn this into a head
	Node<T>* makeNode(const Data& incoming);


	void insertFront(Node<T>* pList, const Data& incomingData);
	void printListIterative(Node<T>* pList) const;

	void destroyList();
	//void destroyListHelper();

public:
	List(Node<T>* newHead = nullptr/* Node<T>* newCur = nullptr*/);

	bool isEmpty(Node<T>* pList);
	void insertFront(const Data& incomingData);
	void printListIterative() const;
	void printData() const;

	void operator=(const Data& incomingData);
	//void openFile(string& file);

	Node<T>* traverse() const;
	Node<T>* getHead() const;
	//~List();
	
};

template<class T>
List<T>::List(Node<T>* newHead)
{
	this->pList = newHead;
}

template<class T>
Node<T>* List<T>::traverse() const
{
	return this->pList;
}


template<class T>
Node<T>* List<T>::makeNode(const Data& incoming)
{
	Node<T>* pTemp = new Node<T>;

	if (pTemp != nullptr)
	{
		pTemp->data = incoming;
		pTemp->next = nullptr;
	}
}

template<class T>
void List<T>::operator=(const Data& incomingData)
{
	List(incomingData);
}


template<class T>
void List<T>::insertFront(const Data& incomingData)
{
	insertFront(pList, incomingData);

}


template<class T>
void List<T>::insertFront(Node<T>* pList, const Data& incomingData)
{
	//this->pList = new Node<T>*(incomingData);
	Node<T>* pTemp = new Node<T>(incomingData);
	//Node<T>* pCur = pList;

	if (pTemp == nullptr)
	{
		cout << "Failed to make a new node" << endl;
	}
	else
	{
		if (pList == nullptr)
		{
			this->pList = pTemp;
		}
		else
		{
			while (pList->getNext() != nullptr)
			{
				pList = pList->getNext();
			}
			pList->setNext(pTemp);
			//pCur = pTemp;
		}

	}

}

template<class T>
Node<T>* List<T>::getHead() const
{
	return this->pList;
}

template<class T>
bool List<T>::isEmpty(Node<T>* pList)
{
	if (pList == NULL)
	{
		return true;
	}
	return false;
}

template<class T>
void List<T>::printListIterative() const
{
	printListIterative(this->pList);
}


template<class T>
void List<T>::printListIterative(Node<T>* pList) const
{
	while (pList != NULL)
	{

		//cout << pList->data << endl;
		//pList = pList->getNext();
	}
}

//template<class T>
//void List<T>::printData() const
//{
//	this->pList->
//	printListIterative(this->pList);
//}

//template<class T>
//inline void List<T>::openFile(string& file)
//{
//	std::ifstream infile(file, std::ios::in);
//
//	if (!infile.is_open())
//	{
//		cout << "file failed to open!" << endl;
//		exit(1);
//	}
//	
//	cout << "temp" << endl;
//}
