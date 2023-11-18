#include<iostream>
#include<stdlib.h>

template <typename T> class Node
{
public:
	T x;
	Node<T>* next;
	Node(T x = 0, Node<T>* next = nullptr) : x(x), next(next) {};
	~Node()
	{
		delete next;
	}
};


template <typename T> class Clist
{
	int size;
	Node<T>* head;
	Node<T>* tail;

public:
	CList() : head(nullptr), tail(nullptr), size(0) {};

	Node<T>* GetElem(int index)
	{
		if (index >= 0)
		{
			Node<T>* temp = head;

			for (int i = 0; i < index; ++i)
			{
				temp = temp->next;
			}
			return temp;
		}
	}

	void Add(T x, int i)
	{
		++size;

		Node<T>* temp(x, head);

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
		Node<T>* temp;

		if (i == 0)
		{
			tail->next = head->next;
			head = head->next;
			delete head;
		}
		if (i > 0)
		{
			temp = GetElem(i - 1);
			Node<T>* prev = temp->next;
			temp->next = temp->next->next;
			if (i % size == 0)
			{
				tail = temp;
			}
			delete prev;
		}
	}

	~Clist()
	{
		Node<T>* temp = head;

		for (int i = 0; i < index; ++i)
		{
			Node<T>* thisnode = temp;
			temp = temp->next;
			delete thisnode;
		}
	}
};