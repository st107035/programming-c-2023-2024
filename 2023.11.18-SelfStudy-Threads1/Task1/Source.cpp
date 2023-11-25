#include <iostream>

#include <thread> //library for using threads

#include <chrono> //library for using time

using namespace std;

void DoWork()
{
	for (size_t i = 0; i < 10; ++i)
	{
		cout << "ID of a thread = " << this_thread::get_id() << "\tDoWork" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int main(int argc, char* argv[])
{
	thread th(DoWork); //constructor's parameter - function pointer, e.g. function name;

	thread th2(DoWork);

	//th.detach(); - if the main thread finishes working this thread breaks
	// th.join() - in this place it blocks the main thread while th is working;

	for (size_t i = 0; i < 10; ++i)
	{
		cout << "ID of a thread = " << this_thread::get_id() << "\tmain" << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	//this_thread::sleep_for(chrono::milliseconds(500)); deactivates the thread; the parameter is time 

	// cout << this_thread::get_id() << endl; thread identificator

	th.join(); // - waiting for another thread to end 
	th2.join();

	return EXIT_SUCCESS;
}