#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <typename T> class Clist
{
private:

	int size;
	Node<T>* head;
	Node<T>* tail;

public:

	int GetSize()
	{
		return this->size;
	}

	Node<T>* GetElem(int i)
	{
		if (i >= 0)
		{
			Node<T>* temp = head;

			for (int j = 0; j < i; ++j)
			{
				temp = temp->next;
			}
			return temp;
		}
	}

	void AddHead(T x)
	{
		++size;

		Node<T>* temp = new Node<T>(x, head);

		if (tail == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			head = temp;
		}
	}

	void AddTail(T x)
	{
		++size;

		Node<T>* temp = new Node<T>(x, head);

		if (tail == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void Delete(int i)
	{
		Node<T>* prev;

		if (i == 0)
		{
			tail->next = head->next;
			head = head->next;
			delete head; 
			--size;
		}
		if (i > 0)
		{
			prev = GetElem(i - 1);
			Node<T>* temp = prev->next;
			prev->next = temp->next;
			if (i % size == 0)
			{
				tail = prev;
			}
			delete temp;
			--size;
		}
	}

	void Print()
	{
		cout << "Clist of " << typeid(T).name() << " { ";
		for (int i = 0; i < size; ++i)
		{
			cout << this->GetElem(i)->x << ", ";
		}
		cout << "}";
	}

	Clist(int size = 0)
	{
		head = nullptr;
		tail = nullptr;

		for (int i = 0; i < size; ++i)
		{
			this->AddTail(T());
		}
	}

	~Clist()
	{
		Node<T>* temp = head;

		while(temp->next != tail)
		{
			Node<T>* thisnode = temp;
			temp = temp->next;
			delete thisnode;
		}

		delete temp;
	}
};

