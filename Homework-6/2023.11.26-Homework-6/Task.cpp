#include "Task.h"
#include<iostream>
#include<exception>

using namespace std;

	Task::Task(char name, int initialt, int t, int priority)
	{
		this->name = name;
		this->initialt = initialt;
		this->t = t;
		if ((priority > 0) && (priority <= 10))
		{
			this->priority = 10 - priority;
		}
		else
		{
			throw exception("Priority is beyond the borders!");
		}
	};

	Task::Task(const Task& task) : name(task.name), initialt(task.initialt), t(task.t), priority(task.priority) {};

	void Task::DoWork()
	{
		if (t > 0)
		{
			--t;
		}
	}

	bool Task::IsDone()
	{
		if (t == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	};

	int Task::GetInitialTime()
	{
		return initialt;
	}

	int Task::GetTime()
	{
		return t;
	}

	int Task::GetPriority()
	{
		return priority;
	}

	char Task::GetName()
	{
		return name;
	}

	Task::~Task() {};

