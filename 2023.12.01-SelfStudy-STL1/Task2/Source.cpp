#include<iostream>
#include<string>
#include<memory> //A file with smart pointers

using namespace std;

template <typename T>
class SmartPointer
{
public:

	SmartPointer(T* ptr)
	{
		this->ptr = ptr;
	}

	T& operator*()
	{
		return *ptr;
	}

	~SmartPointer()
	{
		delete ptr;
	}

private:

	T* ptr;
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	/*<int> sp1 = new int(5);

	SmartPointer<int> sp2 = sp1; -- ошибка */

	auto_ptr<int> ap1(new int(5));
	auto_ptr<int> ap2(ap1);


	unique_ptr<int> up1(new int(5));
	unique_ptr<int> up2;
	up2 = move(up1);
	// int* p = up1.get();
	
	shared_ptr<int> sp1(new int(10));
	shared_ptr<int> sp2(sp1);

	return EXIT_SUCCESS;
}