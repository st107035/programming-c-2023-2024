#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <typename T> class Clist
{
private:

	unsigned size;
	Node<T>* head;
	Node<T>* tail;

public:

	unsigned GetSize()
	{
		return this->size;
	}

	Node<T>* GetElem(unsigned i)
	{
		i = i % size;
		Node<T>* temp = head;

		for (int j = 0; j < i; ++j)
		{				
			temp = temp->next;
		}
		return temp;
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

	void Delete(unsigned i)
	{
		Node<T>* prev;

		if (size != 0)
		{
			if (i == 0)
			{
				tail->next = head->next;
				prev = head;
				head = prev->next;
				delete prev;
				--size;
			}
			if (i > 0)
			{
				prev = GetElem(i - 1);
				Node<T>* temp = prev->next;
				prev->next = temp->next;
				if (i % size == (size - 1))
				{
					tail = prev;
				}
				delete temp;
				--size;
			}
		}
		else
		{
			if (i == 0)
			{
				delete head;
			}
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
		if (size != 0)
		{
			Node<T>* temp = head;

			while (temp->next != tail)
			{
				Node<T>* thisnode = temp;
				temp = temp->next;
				delete thisnode;
			}

			delete temp;
		}
	}
};

