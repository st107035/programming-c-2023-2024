#include <iostream>
#include <ctime> 

using namespace std;

class Task
{
public:

	int t; 
	int priority; //priority will be initially reversed using formula reversed_priority = 10 - real_priority;
	char name;

	Task(char name = '0', int t = 0, int priority = 1)
	{
		this->name = name;
		this->t = t;
		if ((priority > 0) && (priority <= 10))
		{
			this->priority = priority;
		}
		else
		{
			throw exception("Приоритет не попадает в нужный диапазон!");
		}
	};
	Task(const Task& t) : name(t.name), t(t.t), priority(t.priority) {};

	void DoWork()
	{
		if (t > 0)
		{
			--t;
		}
	}

	bool IsDone()
	{
		if (t == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	~Task() {};
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	int n, t, priority;
	int size = 0;
	cin >> n;

	Task* data = new Task [n];

	for (int i = 0; i < n; ++i)
	{
		cin >> t >> priority;
		try
		{
			data[i] = Task('0' + i, t, priority);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
		size += (10 - priority) * t;
	}

	Task* pdata = new Task [size];
	int tempi = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = tempi; j < data[i].priority; ++j)
		{
			pdata[tempi + j] = data[i];
		}

		tempi += data[i].priority;
	}
	
	delete[] data;

	srand(time(0));

	for (int i = 0; i < size; ++i)
	{
		int temp = rand() % size;
		if (pdata[temp].IsDone())
		{
			cout << "Task " << pdata[temp].name << " завершил работу за время " << i + 1 << endl;
		}
		else
		{
			pdata[temp].DoWork();
		}
	}

	delete[] pdata;

	return EXIT_SUCCESS;
}