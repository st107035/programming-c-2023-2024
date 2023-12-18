#pragma once

template <typename T> class Node
{
public:
	T x;
	Node<T>* next;

	Node(T x = 0, Node<T>* next = nullptr) : x(x), next(next) {};

	~Node() {}
};
