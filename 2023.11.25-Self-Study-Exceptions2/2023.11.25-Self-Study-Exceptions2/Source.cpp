#include <iostream>
#include <string>

using namespace std;

void Foo(int value)
{
	if (value < 0)
	{ 
		//throw exception("����� ������ 0!");
		throw "����� ������ 0!";
	}

	if (value == 0)
	{
		throw exception("����� ����� 0!");
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
		cout << "���� 1 " << ex.what() << endl;
	}
	catch (const char* ex)
	{
		cout << "���� 2 " << ex << endl;
	}
	catch (...) //����� ���� ���� ������� ��������� ����� ������ ����������
	{
		cout << "���-�� ����� �� ���...";
	}

	return EXIT_SUCCESS;
}