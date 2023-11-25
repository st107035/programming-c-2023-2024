#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit); //�� ��������� � ifstream ��������� ��������� �������������� ��������, ����� �� �� ��������

	string path = "Sample.txt";

	/*fin.open("Sample.txt");
	(!fin.is_open())
	{
		cout << "������ ��� �������� �����" << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
	}
	fin.close();*/

	try
	{
		//���� ���-�� ���������, �� ��� ����������� � ���� ����� ����������� �� �����
		fin.open(path);
	}
	catch(const exception& ex)
	{
		cout << ex.what() << endl;
		cout << "������ ��� �������� �����" << endl;
	}

	return EXIT_SUCCESS;
}
