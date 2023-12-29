#include "ZmZ.h"
#define m 239

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

ZmZ::ZmZ() : a(0) {};

ZmZ::ZmZ(int a)
{
	this->a = mod(a, m);
}

ZmZ::ZmZ(const ZmZ& z) : a(z.a) {};

ZmZ ZmZ::ReverseElement() const 
{
	for (int i = 1; i < 240; ++i)
	{
		if (mod((this->a * i), m) == 1)
		{
			return ZmZ(i);
			break;
		}
	}
}
ZmZ BinPow(ZmZ z, int n)
{
	if (n > 0)
	{
		if (n % 2 == 1)
		{
			return ZmZ(mod((z * BinPow(z, n - 1)).a, m));
		}
		else
		{
			ZmZ ztemp = ZmZ(mod(BinPow(z, n / 2).a, m));
			return ztemp * ztemp;
		}
	}
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return ZmZ(BinPow(z.ReverseElement(), n));
	}
};

ZmZ& ZmZ::operator=(const ZmZ& z)
{
	a = z.a;
	return *this;
}
ZmZ operator+(ZmZ z1, const ZmZ& z2)
{
	return z1 += z2;
}
ZmZ operator-(ZmZ z1, const ZmZ& z2)
{
	return z1 -= z2;
}
ZmZ operator*(ZmZ z1, const ZmZ& z2)
{
	return z1 *= z2;
}
ZmZ operator/(ZmZ z1, const ZmZ& z2)
{
	return z1 /= z2;
}

ZmZ& operator+=(ZmZ& z1, const ZmZ& z2)
{
	z1.a = mod(z1.a + z2.a, m);
	return z1;
}
ZmZ& operator-=(ZmZ& z1, const ZmZ& z2)
{
	z1.a = mod(z1.a - z2.a, m);
	return z1;
}
ZmZ& operator*=(ZmZ& z1, const ZmZ& z2)
{
	z1.a = mod(z1.a * z2.a, m);
	return z1;
}
ZmZ& operator/=(ZmZ& z1, const ZmZ& z2)
{
	z1.a = mod(z1.a * z2.ReverseElement().a, m);
	return z1;
}

bool operator==(const ZmZ& z1, const ZmZ& z2)
{
	return (z1.a == z2.a);
};
bool operator!=(const ZmZ& z1, const ZmZ& z2)
{
	return (z1.a != z2.a);
};
bool operator<(const ZmZ& z1, const ZmZ& z2)
{
	return (z1.a < z2.a);
};
bool operator>(const ZmZ& z1, const ZmZ& z2)
{
	return (z1.a > z2.a);
};
bool operator<=(const ZmZ& z1, const ZmZ& z2)
{
	return (z1.a <= z2.a);
};
bool operator>=(const ZmZ& z1, const ZmZ& z2)
{
	return (z1.a >= z2.a);
};

std::istream& operator>>(std::istream& in, ZmZ& z)
{
	in >> z.a;
	return in;
}
std::ostream& operator<<(std::ostream& out, const ZmZ& z)
{
	out << z.a << " mod " << m;
	return out;
}

ZmZ::~ZmZ() {};
