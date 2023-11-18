#include "Z239Z.h"
Z239Z::Z239Z() : a(0) {};

Z239Z::Z239Z(int a)
{
	this->a = mod(a, 239);
}

Z239Z::Z239Z(const Z239Z& z) : a(z.a) {};

int mod(int a, int n)
{
	if (a % n < 0)
	{
		return a % n + n;
	}
	else
	{
		return a % n;
	}
}
 
Z239Z Z239Z::operator=(const Z239Z& z)
{
	a = z.a;
	return *this;
} 
Z239Z Z239Z::operator+(const Z239Z& z)
{
	Z239Z znew(a + z.a);
	return znew;
}
Z239Z Z239Z::operator-(const Z239Z& z)
{
	Z239Z znew(a - z.a);
	return znew;
}
Z239Z Z239Z::operator*(const Z239Z& z)
{
	Z239Z znew(a * z.a);
	return znew;
}
Z239Z Z239Z::operator/(const Z239Z& z)
{
	Z239Z znew(a / z.a);
	return znew;
}
Z239Z& Z239Z::operator+=(const Z239Z& z)
{
	a += z.a;
	this->a = mod(a, 239);
	return *this;
}
Z239Z& Z239Z::operator-=(const Z239Z& z)
{
	a -= z.a;
	this->a = mod(a, 239);
	return *this;
}
Z239Z& Z239Z::operator*=(const Z239Z& z)
{
	a *= z.a;
	this->a = mod(a, 239);
	return *this;
}
Z239Z& Z239Z::operator/=(const Z239Z& z)
{
	a /= z.a;
	this->a = mod(a, 239);
	return *this;
}
Z239Z& Z239Z::operator+=(int z)
{
	a += z;
	this->a = mod(a, 239);
	return *this;
}
Z239Z& Z239Z::operator-=(int z)
{
	a -= z;
	this->a = mod(a, 239);
	return *this;
}
Z239Z& Z239Z::operator*=(int z)
{
	a *= z;
	this->a = mod(a, 239);
	return *this;
}
Z239Z& Z239Z::operator/=(int z)
{
	a /= z;
	this->a = mod(a, 239);
	return *this;
}
bool Z239Z::operator==(const Z239Z& z)
{
	return (this->a == z.a);
};
bool Z239Z::operator!=(const Z239Z& z) 
{
	return (this->a != z.a);
};
bool Z239Z::operator>(const Z239Z& z)
{
	return (this->a > z.a);
};
bool Z239Z::operator<(const Z239Z& z) 
{
	return (this->a < z.a);
};
bool Z239Z::operator<=(const Z239Z& z)
{
	return (this->a <= z.a);
};
bool Z239Z::operator>=(const Z239Z& z)
{
	return (this->a >= z.a);
};
bool Z239Z::operator==(int z)
{
	return (this->a == mod(z, 239));
};
bool Z239Z::operator!=(int z)
{
	return (this->a != mod(z, 239));
};
bool Z239Z::operator>(int z)
{
	return (this->a > mod(z, 239));
};
bool Z239Z::operator<(int z)
{
	return (this->a < mod(z, 239));
};
bool Z239Z::operator<=(int z)
{
	return (this->a <= mod(z, 239));
};
bool Z239Z::operator>=(int z)
{
	return (this->a >= mod(z, 239));
};
Z239Z Z239Z::ReverseElement(const Z239Z& z)
{
	for (int i = 1; i < 240; ++i)
	{
		if (mod((z.a * i), 239) == 1)
		{
			return i;
			break;
		}
	}
}
Z239Z Z239Z::BinPow(Z239Z z, int n)
{
	if (n > 0)
	{
		if (n % 2 == 1)
		{
			return mod((z * BinPow(z, n - 1)).a, 239);
		}
		else
		{
			return mod(BinPow(z + z, n / 2).a, 239);
		}
	}
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return;
	}
};
std::istream& operator>>(std::istream& in, Z239Z& z)
{
	in >> z.a;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Z239Z& z)
{
	out << z.a << " mod 239";
	return out;
}

Z239Z::~Z239Z() {};
