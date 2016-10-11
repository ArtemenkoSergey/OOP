
#include "fraction.h"




unsigned int GCD(unsigned int a, unsigned int b);
unsigned int LCM(unsigned int a, unsigned int b);

unsigned int Fraction::count = 0;


Fraction::Fraction(int n, int d)
{
	count++;
	setFraction(n,d);
	// std::cout << "Fraction(int int). count=" << count << std::endl;
}

Fraction::Fraction(const Fraction &other)
{
	if (other!=NULL)
	{
		numerator = other.numerator;
		denominator = other.denominator;
	}
	else
		setFraction(0,1);
	count++;
}

Fraction::~Fraction()
{
	count--;
	// std::cout << "~Fraction(). count=" << count << std::endl;
}

int Fraction::setFraction(int n, int d)
{
	// std::cout << (int)sign << " " << n << " " << d << " " << std::endl;
	n *= (d < 0)? -1 : 1;
	d *= (d < 0)? -1 : 1;
	// std::cout << (int)sign << " " << n << " " << d << " "  << std::endl;
	numerator = n;
	if (d!=0){
		denominator = d;
	}
	else{
		denominator = 1;
		return SET_ZERO_DENOMINATOR_ERROR;
	}
	reduction();
	return NO_ERRORS;
}


int Fraction::reduction()
{
	unsigned int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return gcd;
}


void Fraction::input()
{
	int err = 1;
	std::cout << "введите числитель и знаменатель дроби: " << std::endl;
	while (err != 0)
	{
		int n, d;
		std::cout << "числитель: ";
		std::cin >> n;
		std::cout << "знаменатель: ";
		std::cin >> d;
	
		int err = setFraction(n,d);
		if (err != NO_ERRORS)
			std::cout << "Ошибка ввода данных. Повтороно введите числитель и знаменатель." << std::endl;
	}
}

void Fraction::show()
{
	std::cout << numerator << "/" << denominator;
}

// int Fraction::getStr()
// {}

double Fraction::getDouble()
{
	return (double)numerator/(double)denominator; 
}

int Fraction::add(const Fraction &other)
{
	unsigned int lcm = LCM(denominator, other.denominator);
	long int tNumerator = (numerator*lcm/denominator)+(other.numerator*lcm/other.denominator);
	return setFraction(tNumerator,lcm);
}

int Fraction::sub(const Fraction &other)
{
	unsigned int lcm = LCM(denominator, other.denominator);
	long int tNumerator = (numerator*lcm/denominator)-(other.numerator*lcm/other.denominator);
	return setFraction(tNumerator,lcm);
}

int Fraction::mul(const Fraction &other)
{
	return setFraction(numerator*other.numerator, denominator*other.denominator);
}

int Fraction::div(const Fraction &other)
{	
	return setFraction(numerator*other.denominator, denominator*other.numerator);
}



unsigned int GCD(unsigned int a, unsigned int b)
{
	unsigned int r = a%b;
	while (r)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

unsigned int LCM(unsigned int a, unsigned int b)
{
	unsigned int r = a*b/GCD(a,b);
	return r;
}