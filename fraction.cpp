
#include "fraction.h"

#define NO_ERRORS 0
#define SET_ZERO_DENOMINATOR_ERROR -1


unsigned int GCD(unsigned int a, unsigned int b);
unsigned int LCM(unsigned int a, unsigned int b);

unsigned int Fraction::count = 0;


Fraction::Fraction(unsigned int n, unsigned int d)
{
	count++;
	int err = setFraction(n,d);
	std::cout << "Fraction(int int). count=" << count << std::endl;
}

Fraction::Fraction(const Fraction &other)
{
	sign = other.sign;
	numerator = other.numerator;
	denominator = other.denominator;
	count++;
}

Fraction::~Fraction()
{
	count--;
	std::cout << "~Fraction(). count=" << count << std::endl;
}

int Fraction::setFraction(unsigned int n, unsigned int d)
{
	sign = 1;
	// std::cout << (int)sign << " " << n << " " << d << " " << std::endl;
	sign *= (n>=0)? 1:-1;
	sign *= (d>=0)? 1:-1;
	n *= (n>=0)? 1:-1;
	d *= (d>=0)? 1:-1;
	// std::cout << (int)sign << " " << n << " " << d << " "  << std::endl;
	numerator = n;
	if (d!=0){
		denominator = d;
	}
	else{
		denominator = 1;
		return SET_ZERO_DENOMINATOR_ERROR;
	}
	// reduction();
	return NO_ERRORS;
}


int Fraction::reduction()
{
	unsigned int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return gcd;
}


int Fraction::input()
{
	int n, d;
	std::cout << "numerator: ";
	std::cin >> n;
	std::cout << "denominator: ";
	std::cin >> d;

	int err = setFraction(n,d);
	return err;
}

int Fraction::show()
{
	if (sign == -1)
		std::cout << " -- ";
	std::cout << numerator << " / " << denominator << std::endl;
	return NO_ERRORS;
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
	long int tNumerator = sign*(numerator*lcm/denominator)+other.sign*(other.numerator*lcm/other.denominator);
	return setFraction(tNumerator,lcm);
}

int Fraction::sub(const Fraction &other)
{
	unsigned int lcm = LCM(denominator, other.denominator);
	long int tNumerator = sign*(numerator*lcm/denominator)-other.sign*(other.numerator*lcm/other.denominator);
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