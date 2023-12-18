#include <iostream>
#include <thread>
#include "Queue.h"
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
	queue<int> q;

	thread t1([&q]()
		{
			for (int i = 0; i < 10; ++i)
			{
				this_thread::sleep_for(chrono::milliseconds(2));
				q.Print();
			}
		});

	thread t2([&q]()
		{
			for (int i = 0; i < 10; ++i)
			{
				this_thread::sleep_for(chrono::milliseconds(1));
				q.push(i);
			}
		});

	thread t3([&q]()
		{
			for (int i = 0; i < 10; ++i)
			{
				this_thread::sleep_for(chrono::milliseconds(3));
				try
				{
					q.pop();
				}
				catch (const exception& ex)
				{
					cout << ex.what() << endl;
				}
			}
		});

	t1.join();
	t2.join();
	t3.join();

	return EXIT_SUCCESS;
}