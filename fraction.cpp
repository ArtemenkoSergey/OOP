
#include "fraction.h"



// #include <iostream>


unsigned int Fraction::count = 0;
int Fraction::err = 0;


Fraction::Fraction(const int n, const int d)
{
	count++;
	err = setFraction(n,d);
	// std::cout << "Fraction(int int). count=" << count << std::endl;
}

Fraction::Fraction(const char* str)
{
	int lenght = strlen(str);
	int divIndex = 0;
	while(divIndex < lenght && *(str+divIndex)!='/') divIndex++;

	int i = divIndex+1;
	while(i < lenght && *(str+i)==' ') i++;
	int tDenominator;
	if (i < lenght)
		tDenominator = atoi(str+i);
	else
		tDenominator = 1;

	i = divIndex-1;
	while(i>=0 && *(str+i) == ' ') i--;
	while(i>=0 && isdigit(*(str+i))) i--;
	if (*(str+i) != '-') i++;
	int tNumerator = atoi(str+i);
	i--;

	if (*(str+i) == '+') i--;
	int tInt = 0;
	while(i>=0 && *(str+i)==' ') i--;
	if (*(str+i)=='*') i--;
	while(i>=0 && *(str+i)==' ') i--;
	if (i>0)
	{
		while(i>=0 && isdigit(*(str+i))) i--;
		if (*(str+i) != '-') i++;
		tInt = atoi(str+i);
	}

	err = setFraction(tInt*tNumerator, tDenominator);
	count++;
}

// Fraction(const &string str)
// {

// }

Fraction::Fraction(const Fraction &other)
{
	numerator = other.numerator;
	denominator = other.denominator;
}

Fraction::Fraction(const Fraction *other)
{
	if (other != NULL)
	{
		numerator = other->numerator;
		denominator = other->denominator;
	}
	else
	{	
		setFraction(0,1);
		err = fractionErrors::GIVEN_NULL_POINTER;
	}
	count++;
}

Fraction::~Fraction()
{
	count--;
	// std::cout << "~Fraction(). count=" << count << std::endl;
}

int Fraction::setFraction(int n, int d)
{
	n *= (d < 0)? -1 : 1;
	d *= (d < 0)? -1 : 1;

	numerator = n;
	if (d!=0)
	{
		denominator = d;
	}
	else
	{
		denominator = 1;
		err = fractionErrors::SET_ZERO_DENOMINATOR_ERROR;
		return err;
	}

	reduction();
	// std::cout << "sF3 n/d " << n << " / " << d << std::endl;
	err = fractionErrors::NO_ERRORS;
	return err;
}


int Fraction::reduction()
{
	int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return gcd;
}

std::string Fraction::toStr()
{
	char* str = new char [25];
	int i = ITS(str, numerator);
	// std::cout << "i " << i << " n " << str << std::endl;
	str[i] = '/';
	ITS(&(str[i+1]), denominator);
	// std::cout << "i " << i << " n/d " << str << std::endl;
	std::string result(str);
	delete[] str;
	return result;
}

double Fraction::toDouble()
{
	return (double)numerator/(double)denominator; 
}

Fraction Fraction::add(const Fraction &other)
{
	int lcm = LCM(denominator, other.denominator);
	int tNumerator = (numerator*lcm/denominator)+(other.numerator*lcm/other.denominator);
	Fraction result(tNumerator, lcm);
	return result;
}

Fraction Fraction::sub(const Fraction &other)
{
	int lcm = LCM(denominator, other.denominator);
	int tNumerator = (numerator*lcm/denominator)-(other.numerator*lcm/other.denominator);
	Fraction result(tNumerator, lcm);
	return result;
}

Fraction Fraction::mul(const Fraction &other)
{
	Fraction result(numerator*other.numerator, denominator*other.denominator);
	return result;
}
Fraction Fraction::div(const Fraction &other)
{	
	Fraction result(numerator*other.denominator, denominator*other.numerator);
	return result;
}


