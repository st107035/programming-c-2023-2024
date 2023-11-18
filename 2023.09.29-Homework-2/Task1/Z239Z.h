#pragma once
#include<iostream>
class Z239Z
{
	int a;
public:
	Z239Z();
	Z239Z(int a);
	Z239Z(const Z239Z& z);

	Z239Z operator=(const Z239Z& z);
	Z239Z operator+(const Z239Z& z);
	Z239Z operator-(const Z239Z& z);
	Z239Z operator*(const Z239Z& z);
	Z239Z operator/(const Z239Z& z);
	Z239Z& operator+=(const Z239Z& z);
	Z239Z& operator-=(const Z239Z& z);
	Z239Z& operator*=(const Z239Z& z);
	Z239Z& operator/=(const Z239Z& z);
	Z239Z& operator+=(int z);
	Z239Z& operator-=(int z);
	Z239Z& operator*=(int z);
	Z239Z& operator/=(int z);
	bool operator==(const Z239Z& z);
	bool operator!=(const Z239Z& z);
	bool operator>(const Z239Z& z);
	bool operator<(const Z239Z& z);
	bool operator<=(const Z239Z& z);
	bool operator>=(const Z239Z& z);
	bool operator==(int z);
	bool operator!=(int z);
	bool operator>(int z);
	bool operator<(int z);
	bool operator<=(int z);
	bool operator>=(int z);
	Z239Z ReverseElement(const Z239Z& z);
	Z239Z BinPow(Z239Z, int n);
	friend std::istream& operator>>(std::istream& in, Z239Z& z);
	friend std::ostream& operator<<(std::ostream& out, const Z239Z& z);

	~Z239Z();
};

