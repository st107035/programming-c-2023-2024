#pragma once
#include<iostream>

class ZmZ
{
	int a;

public:
	ZmZ();
	ZmZ(int a);
	ZmZ(const ZmZ& z);

	void operator=(const ZmZ& z);

	ZmZ operator+(const ZmZ& z);
	ZmZ operator-(const ZmZ& z);
	ZmZ operator*(const ZmZ& z);
	ZmZ operator/(const ZmZ& z);
	ZmZ& operator+=(const ZmZ& z);
	ZmZ& operator-=(const ZmZ& z);
	ZmZ& operator*=(const ZmZ& z);
	ZmZ& operator/=(const ZmZ& z);

	bool operator==(const ZmZ& z);
	bool operator!=(const ZmZ& z);
	bool operator>(const ZmZ& z);
	bool operator<(const ZmZ& z);
	bool operator<=(const ZmZ& z);
	bool operator>=(const ZmZ& z);

	ZmZ ReverseElement();

	friend ZmZ BinPow(ZmZ z, int n);
	friend std::istream& operator>>(std::istream& in, ZmZ& z);
	friend std::ostream& operator<<(std::ostream& out, const ZmZ& z);

	~ZmZ();
};

