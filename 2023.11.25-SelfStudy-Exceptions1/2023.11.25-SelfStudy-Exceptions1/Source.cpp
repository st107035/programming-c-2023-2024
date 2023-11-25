#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit); //По умолчанию в ifstream отключена обработка исключительных ситуаций, здесь мы ее включили

	string path = "Sample.txt";

	/*fin.open("Sample.txt");
	(!fin.is_open())
	{
		cout << "Ошибка при открытии файла" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}
	fin.close();*/

	try
	{
		//Если что-то сломалось, то все последующее в этом блоке выполняться не будет
		fin.open(path);
	}
	catch(const exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Ошибка при открытии файла" << endl;
	}

	return EXIT_SUCCESS;
}
