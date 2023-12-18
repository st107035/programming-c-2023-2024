#pragma once
#include<mutex>
#include <iostream>
#include"Node.h"

using namespace std;

template<typename T> class queue
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size;

	mutex mtx;

public:
	queue() : head(nullptr), tail(nullptr), size(0) {};

	void push(T x)
	{
		Node<T>* temp = new Node<T>(x);

		lock_guard<mutex> lg(mtx);

		if (head == nullptr)
		{
			head = temp;
			tail = head;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
		++size;
	}

	void pop()
	{
		mtx.lock();

		if (this->empty())
		{
			mtx.unlock();
			throw exception("Pop from empty queue!");
		}

		Node<T>* temp = head;

		head = head->next;

		if (head == nullptr)
		{
			tail = nullptr;
		}

		--size;

		mtx.unlock();

		delete temp;
	}

	T front()
	{
		if (this->empty())
		{
			throw exception("The queue is empty!");
		}

		return head->data;
	}

	bool empty()
	{
		if (head != nullptr)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	int GetSize()
	{
		return size;
	}

	void Print()
	{
		lock_guard<mutex> lg(mtx);
		cout << "Queue " << "of " << typeid(T).name() << " {";
		Node<T>* temp = head;
		for (int i = 0; i < size; ++i)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << "}" << endl;
	}

	~queue()
	{
		lock_guard<mutex> lg(mtx);

		if (head != nullptr)
		{
			while (head->next != nullptr)
			{
				Node<T>* temp = head;
				head = head->next;
				delete temp;
			}
		}
		delete head;
	}
};

