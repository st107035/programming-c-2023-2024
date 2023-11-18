#include<iostream>
#include<cmath>

class Expression
{
public: 
	Expression() = default;
	virtual void print() = 0;
	virtual double calc(double x) = 0;
	virtual Expression* derivative() = 0;
	virtual Expression* copy() = 0;
	virtual ~Expression() = default;
};

class Constant : public Expression
{
public:
	double c;

	Constant(double c = 0) : c(c) {};

	void print()
	{
		std::cout << c;
	}
	double calc(double x)
	{
		return c;
	}
	Expression * derivative()
	{
		return new Constant(0);
	}
	Constant* copy()
	{
		return new Constant(c);
	}
};

class Value : public Expression
{
public:
	double x;

	Value(double x) : Expression(), x(x) {};

	void print()
	{
		std::cout << "x";
	}

	double calc(double x)
	{
		return x;
	}

	Expression* derivative()
	{
		return new Constant(1);
	}

	Expression* copy()
	{
		return new Value(x);
	}
};

class Sum : public Expression
{
public:

	Expression * a, * b;

	Sum(Expression* a = nullptr, Expression* b = nullptr) : Expression(), a(a), b(b) {};

	void print()
	{
		std::cout << "(";
		a->print();
		std::cout << " + ";
		b->print();
		std::cout << ")";
	}
	double calc(double x)
	{
		return a->calc(x) + b->calc(x);
	}
	Expression* derivative()
	{
		return new Sum(a->derivative(), b->derivative());
	}
	Expression* copy()
	{
		return new Sum(a->copy(), b->copy());
	}

	~Sum() 
	{
		delete a;
		delete b;
	};
};

class Substr : public Expression
{
public:

	Expression* a, * b;

	Substr(Expression* a = nullptr, Expression* b = nullptr) : Expression(), a(a), b(b) {};
	void print()
	{
		std::cout << "(";
		a->print();
		std::cout << " - ";
		b->print();
		std::cout << ")";
	}
	double calc(double x)
	{
		return a->calc(x) - b->calc(x);
	}
	Expression* derivative()
	{
		return new Substr(a->derivative(), b->derivative());
	}
	Expression* copy()
	{
		return new Substr(a->copy(), b->copy());
	}

	~Substr() 
	{
		delete a;
		delete b;
	};
};

class Product : public Expression
{
public:

	Expression* a, * b;

	Product(Expression* a = nullptr, Expression* b = nullptr) : Expression(), a(a), b(b) {};
	void print()
	{
		std::cout << "(";
		a->print();
		std::cout << "*";
		b->print();
		std::cout << ")";
	}
	double calc(double x)
	{
		return a->calc(x) * b->calc(x);
	}
	Expression* derivative()
	{
		return new Sum(new Product(a->derivative(), b->copy()), new Product(a->copy(), b->derivative()));
	}
	Expression* copy()
	{
		return new Product(a->copy(), b->copy());
	}

	~Product() 
	{
		delete a;
		delete b;
	};
};

class Frac : public Expression
{
public:

	Expression* a, * b;

	Frac(Expression* a = nullptr, Expression* b = nullptr) : Expression(), a(a), b(b) {};
	void print()
	{
		std::cout << "(";
		a->print();
		std::cout << "/";
		b->print();
		std::cout << ")";
	}
	double calc(double c)
	{
		if (b->calc(c) != 0)
		{
			return a->calc(c) / b->calc(c);
		}
	}
	Expression* derivative()
	{
		return new Frac(new Substr(new Product(a->derivative(), b->copy()),new Product(b->derivative(), a->copy())), new Product(b->derivative(), b->derivative()));
	}
	Expression* copy()
	{
		return new Frac(a->copy(), b->copy());
	}

	~Frac()
	{ 
		delete a; 
		delete b;
	};
};

class Sin: public Expression
{
public:

	Expression* a;

	Sin(Expression* a = nullptr) : Expression(), a(a) {};

	void print()
	{
		std::cout << "Sin(";
		a->print();
		std::cout << ")";
	}

	double calc(double x)
	{
		return sin(a->calc(x));
	}

	Expression* derivative();

	Expression* copy()
	{
		return new Sin(a->copy());
	}

	~Sin()
	{
		delete a;
	}
};

class Cos : public Expression
{
public:

	Expression* a;

	Cos(Expression* a = nullptr) : Expression(), a(a) {};

	void print()
	{
		std::cout << "Cos(";
		a->print();
		std::cout << ")";
	}

	double calc(double c)
	{
		return cos(a->calc(c));
	}

	Expression* derivative()
	{
		return new Product( new Product(new Constant(-1), new Sin(a->copy())), a->derivative());
	}

	Expression* copy()
	{
		return new Product(new Product(new Sin(a->copy()), new Constant(-1)), a->derivative());
	}

	~Cos()
	{
		delete a;
	}
};

Expression* Sin::derivative()
{
	return new Product(new Cos(a->copy()), a->derivative());
}

class Exp : public Expression
{
public:

	Expression* a;

	Exp(Expression* a = nullptr) : Expression(), a(a) {};

	void print()
	{
		std::cout << "exp(";
		a->print();
		std::cout << ")";
	}

	double calc(double c)
	{
		return exp(a->calc(c));
	}

	Expression* derivative()
	{
		return new Product(new Exp(a->copy()), a->derivative());
	}

	Expression* copy()
	{
		return new Exp(a->copy());
	}

	~Exp()
	{
		delete a;
	}
};

class Ln: public Expression
{
public:

	Expression* a;

	Ln(Expression* a = nullptr) : Expression(), a(a) {};

	void print()
	{
		std::cout << "ln(";
		a->print();
		std::cout << ")";
	}

	double calc(double c)
	{
		return log(a->calc(c));
	}

	Expression* derivative()
	{
		return new Product(new Frac(new Constant(1), a->copy()), a->derivative());
	}

	Expression* copy()
	{
		return new Ln(a->copy());
	}

	~Ln()
	{
		delete a;
	}
};

int main(int argc, char* argv[])
{
	double x = 7;

	Expression* exp = new Sin(new Sum(new Value(x), new Product(new Constant(2), new Value(x))));

	exp->print();

	std::cout << std::endl;

	Expression* expd = exp->derivative();

	expd->print();

	delete exp;
	delete expd;

	return EXIT_SUCCESS;
}