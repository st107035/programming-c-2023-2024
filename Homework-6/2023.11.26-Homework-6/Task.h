#pragma once
class Task
{
private:

	char name;
	int initialt;
	int t;
	int priority; //priority will be initially reversed using formula reversed_priority = 10 - real_priority;

public:

	Task(char name = '0', int initialt = 0, int t = 0, int priority = 1);
	Task(const Task& task);

	void DoWork();

	bool IsDone();

	int GetInitialTime();

	int GetTime();

	int GetPriority();

	char GetName();

	~Task();
};

