#include <iostream>
#include <fstream>
#include <ctime> 
#include"Task.h"

using namespace std;

int* Fiber(ifstream &f, bool print_flag)
{
	int n, t, priority;
	int size = 0;

	f.open("Tasks.txt");
	f >> n;
	Task* data = new Task[n];
	int* rdata = new int[n];

	for (int i = 0; i < n; ++i)
	{
		f >> t >> priority;
		try
		{
			data[i] = Task('0' + i, t, t, priority);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
		size += (10 - priority) * t;
	}

	Task** pdata = new Task * [size];

	Task** pdatat = new Task * [size];

	int tempi = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < data[i].GetPriority() * data[i].GetTime(); ++j)
		{
			pdata[tempi + j] = &data[i];
		}

		tempi += data[i].GetPriority() * data[i].GetTime();
	}

	srand(time(0));

	for (int i = 0; i < 10000; ++i)
	{
		if (size == 0)
		{
			break; 
		}

		int temp = rand() % size;

		if (pdata[temp]->IsDone())
		{
			if (print_flag)
			{
				cout << "Task " << pdata[temp]->GetName() << " with priority " << pdata[temp]->GetPriority()  << " finished after " << i + 1 << " tacts " << endl;
			}

			rdata[(int)pdata[temp]->GetName() - 48] = i + 1;

			int sizet = size - pdata[temp]->GetInitialTime() * pdata[temp]->GetPriority();

			int k = 0;

			for (int j = 0; j < size; ++j)
			{
				if (pdata[j]->GetName() != pdata[temp]->GetName())
				{
					pdatat[k] = pdata[j];

					k += 1;
				}
			}

			for (int j = 0; j < size; ++j)
			{
				if (j < sizet)
				{
					pdata[j] = pdatat[j];
				}
				else
				{
					pdata[j] = nullptr;
				}
			}

			size = sizet;
		}
		else
		{
			pdata[temp]->DoWork();
		}
	}

	f.close();

	delete[] data;

	delete[] pdata;

	delete[] pdatat;

	return rdata;
}

int main(int argc, char* argv[])
{
	int n, t, priority;
	int temp = 0;

	ifstream f;
	f.open("Tasks.txt");

	f >> n;
	int* time_of_tasks = new int[n] {0};
	for (int i = 0; i < n; ++i)
	{
		f >> t >> priority;
		temp += t;
		cout << "Task " << i << " with priority " << priority << " finished after " << temp << " tacts " << endl;
	}

	cout << "FIBER STARTED" << endl;

	f.close();

	for (int i = 0; i < 10; ++i)
	{
		int* temp = new int[n];
		temp = Fiber(f, 0);
		for (int j = 0; j < n; ++j)
		{
			time_of_tasks[j] += temp[j];
		}
		delete[] temp;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << "Task " << i << " finishes on average after " << time_of_tasks[i] / n << " tacts " << endl;
	}

	delete[] time_of_tasks;
	return EXIT_SUCCESS;
}