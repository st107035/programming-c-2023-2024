#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) 
{
	setlocale(LC_ALL, "ru");

	vector<int> v = { 1, 2, 3, 4, 5, 6 };

	vector<int>::iterator it;

	it = v.begin(); 
	it++;
	*it = 1000;

	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " " << endl;
	}

	/*	for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
	{
		*i = 5 -- ������
		cout << *i << " " << endl;
	} 
	 � ������� ������������ �������� ��������� ����� ������������ ���������, �� ���� ����� �������� ����������� �������� ����� v.cbegin(), v.cend()

	 for (vector<int>::iterator i = v.rbegin(); i != v.rend(); ++i) -- ������
	{
		cout << *i << " " << endl;
	}

	*/

	// �� ��� ��������� ������� ���������� ��� �������

	advance(it, 1);
	v.insert(it, 3);
	//v.erase(it);

	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " " << endl;
	}

	return EXIT_SUCCESS;
}