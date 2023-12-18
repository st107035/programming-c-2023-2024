#pragma once
class Sample //We created an extra class with PUBLIC methods
{
private: 
	int a;

public:

	virtual int f1(); //We will get the private method using vtable
	virtual void f2();
	virtual char f3();

	Sample(int a);
	~Sample();
};

