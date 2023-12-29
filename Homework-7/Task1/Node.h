#pragma once
template<typename T> class Node
{
public:

	T data;
	Node* next;

	Node(T data = T(), Node* next = nullptr) : data(data), next(next) {};

//	~Node() {};

};

