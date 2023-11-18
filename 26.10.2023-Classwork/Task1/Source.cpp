#include<iostream>
#include<string>

class Property
{
protected:
	int worth;
	std::string adress;

public:
	Property(int worth = 0, std::string adress = "") : worth(worth), adress(adress) {};
	virtual double Tax() = 0;

	virtual ~Property() {};
};

class Appartment : public Property
{
public:
	Appartment(int worth = 0, std::string adress = "") : Property(worth, adress) {};

	double Tax()
	{
		return 0.001 * worth;
	}

	~Appartment() {};
};

class Car : public Property
{
public:
	Car(int worth = 0, std::string adress = "") : Property(worth, adress) {};

	double Tax()
	{
		return 0.005 * worth;
	}

	~Car() {};
};

class CountryHouse : public Property
{
public:
	CountryHouse(int worth = 0, std::string adress = "") : Property(worth, adress) {};

	double Tax()
	{
		return 0.002 * worth;
	}

	~CountryHouse() {};
};

int main(int argc, char* argv[])
{
	Property** A = new Property* [7];

	A[0] = new Appartment(2000000, "101");
	A[1] = new Appartment(2500000, "105");
	A[2] = new Appartment(2300000, "107");
	A[3] = new Car(120000, "102");
	A[4] = new Car(3500000, "103");
	A[5] = new CountryHouse(1200000, "104");
	A[6] = new CountryHouse(3200000, "106");

	for (int i = 0; i < 7; ++i)
	{
		std::cout << (*A[i]).Tax() << std::endl;
	}

	for (int i = 0; i < 7; ++i)
	{
		delete A[i];
	}

	delete[] A;

	return EXIT_SUCCESS;
}