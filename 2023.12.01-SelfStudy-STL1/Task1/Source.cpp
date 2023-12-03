#include <iostream> 
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	vector<int> v;

	v.push_back(2);
	v.push_back(21);
	v.push_back(23);

	v[0] = 100;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	try
	{
		cout << v.at(19) << endl; // This methods checks the borders of the vector index; Works slowly
	}
	catch (const std::out_of_range& ex)
	{
		cout << ex.what() << endl;
	}


	v.pop_back(); // removes the last element
	v.clear(); // removes ALL the elements

	vector<int> u = { 0, 20, 3, 45 };

	u.reserve(10); // pointing how many "elements" could be in capacity 

	//u.capacity(); -- How many elements can fit in

	cout << u.size() << " " << u.capacity() << endl;
	u.shrink_to_fit();
	cout << u.size() << " " << u.capacity() << endl;

	//v.empty() -- checks if there are any elements

	//u.resize(10); -- changes the size;

	return EXIT_SUCCESS;
}