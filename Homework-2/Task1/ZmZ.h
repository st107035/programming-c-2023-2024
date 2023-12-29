#pragma once
#include<iostream>

class ZmZ
{
private:
	int a;

public:
	ZmZ();
	ZmZ(int a);
	ZmZ(const ZmZ& z);

	ZmZ ReverseElement() const;

	ZmZ& operator=(const ZmZ& z);

	friend ZmZ operator+(ZmZ z1, const ZmZ& z2);
	friend ZmZ operator-(ZmZ z1, const ZmZ& z2);
	friend ZmZ operator*(ZmZ z1, const ZmZ& z2);
	friend ZmZ operator/(ZmZ z1, const ZmZ& z2);

	friend ZmZ& operator+=(ZmZ& z1, const ZmZ& z2);
	friend ZmZ& operator-=(ZmZ& z1, const ZmZ& z2);
	friend ZmZ& operator*=(ZmZ& z1, const ZmZ& z2);
	friend ZmZ& operator/=(ZmZ& z1, const ZmZ& z2);

	friend bool operator==(const ZmZ& z1, const ZmZ& z2);
	friend bool operator>(const ZmZ& z1, const ZmZ& z2);
	friend bool operator<(const ZmZ& z1, const ZmZ& z2);
	friend bool operator!=(const ZmZ& z1, const ZmZ& z2);
	friend bool operator>=(const ZmZ& z1, const ZmZ& z2);
	friend bool operator<=(const ZmZ& z1, const ZmZ& z2);

	friend ZmZ BinPow(ZmZ z, int n);
	friend std::istream& operator>>(std::istream& in, ZmZ& z);
	friend std::ostream& operator<<(std::ostream& out, const ZmZ& z);

	~ZmZ();
};

