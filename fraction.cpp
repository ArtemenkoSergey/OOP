#include <iostream>

#include "fraction.h"

#define SET_ZERO_DENOMINATOR_ERROR -1

long int GCD(long int a, long int b);

unsigned int Fraction::counter = 0;

Fraction::Fraction()
{
	counter++;
	int err = setFraction(0,1);

	std::cout << "Fraction() counter " << counter << std::endl;
}

Fraction::Fraction(long int n, long int d)
{
	counter++;
	int err = setFraction(n,d);
	std::cout << "Fraction(int int) counter " << counter << std::endl;
}

Fraction::~Fraction()
{
	counter--;
	std::cout << "~Fraction() counter " << counter << std::endl;
}

int Fraction::setFraction(long int n, long int d)
{
	sign = 1;
	std::cout << sign << " " << n << " " << d << " " << std::endl;
	sign *= (n>0)? 1:-1;
	sign *= (d>0)? 1:-1;
	n *= (n>0)? 1:-1;
	d *= (d>0)? 1:-1;
	std::cout << sign << " " << n << " " << d << " "  << std::endl;
	numerator = n;
	if (d!=0){
		denominator = d;
	}
	else{
		denominator = 1;
		return SET_ZERO_DENOMINATOR_ERROR;
	}
	// reduction();
	return 0;
}

int Fraction::reduction()
{
	long int gcd = GCD(numerator, denominator);
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
}





long int GCD(long int a, long int b)
{
	long int r = a%b;
	while (r)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}