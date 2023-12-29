#include <iostream>
#include "ZmZ.h"

using namespace std;

int main(int argc, char* argv[])
{
	ZmZ z1, z2;
	int z;

	cin >> z1 >> z2 >> z;

	cout << "z1: " << z1 << " z2: " << z2 << endl;
	cout << "z1 + z2 = " << z1 + z2 << endl;
	cout << "z1 - z2 = " << z1 - z2 << endl;
	cout << "z1 * z2 = " << z1 * z2 << endl;
	cout << "z1 / z2 = " << z1 / z2 << endl;
	cout << "(z1 == z2) " << boolalpha << (z1 == z2) << endl;
	cout << "(z1 != z2) " << boolalpha << (z1 != z2) << endl;
	cout << "(z1 > z2) " << boolalpha << (z1 > z2) << endl;
	cout << "(z1 < z2) " << boolalpha << (z1 < z2) << endl;
	cout << "(z1 >= z2) " << boolalpha << (z1 >= z2) << endl;
	cout << "(z1 <= z2) " << boolalpha << (z1 <= z2) << endl;
	z1 += z2;
	cout << "z1 after z1 += z2" << z1 << endl;
	z1 -= z2;
	cout << "z1 after z1 -= z2" << z1 << endl;
	z1 *= z2;
	cout << "z1 after z1 *= z2" << z1 << endl;
	z1 /= z2;
	cout << "z1 after z1 /= z2" << z1 << endl;
	cout << "z1 ^ z = " << BinPow(z1, z) << endl;
	cout << "Reverse element of z1 = " << z1.ReverseElement() << endl;
	cout << "Reverse element of z2 = " << z2.ReverseElement() << endl;
	cout << "z1 + z = " << z1 + z << endl;
	cout << "z1 - z = " << z1 - z << endl;
	cout << "z1 * z = " << z1 * z << endl;
	cout << "z1 / z = " << z1 / z << endl;
	cout << "(z1 == z) " << boolalpha << (z1 == z) << endl;
	cout << "(z1 != z) " << boolalpha << (z1 != z) << endl;
	cout << "(z1 > z) " << boolalpha << (z1 > z) << endl;
	cout << "(z1 < z) " << boolalpha << (z1 < z) << endl;
	cout << "(z1 >= z) " << boolalpha << (z1 >= z) << endl;
	cout << "(z1 <= z) " << boolalpha << (z1 <= z) << endl;


	return EXIT_SUCCESS;
}