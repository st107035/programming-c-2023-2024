#include <iostream>
#include <string>

using namespace std;

void Foo(int value)
{
	if (value < 0)
	{ 
		//throw exception("Число меньше 0!");
		throw "Число меньше 0!";
	}

	if (value == 0)
	{
		throw exception("Число равно 0!");
	}

	if (value == 1)
	{
		throw 1;
	}

	cout << value << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	Foo(55);

	try
	{
		Foo(1);
	}
	catch (const exception &ex)
	{
		cout << "Блок 1 " << ex.what() << endl;
	}
	catch (const char* ex)
	{
		cout << "Блок 2 " << ex << endl;
	}
	catch (...) //такой блок надо ставить последним среди блоков исключений
	{
		cout << "Что-то пошло не так...";
	}

	return EXIT_SUCCESS;
}