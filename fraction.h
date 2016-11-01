// Вариант № 5. Дробь.
// Класс хранит значение дроби. Предусмотреть метод сокращения дроби, умножения и деления на другую дробь (передавать как параметры функции).

// Класс должен включать в себя:
// 	Данные-члены, типы и количество которых хорошо подходят для хранения и представления соответствующих значений.
// 	Конструктор по умолчанию, конструктор с параметрами (возможно, не один), конструктор копирования и деструктор. 
// 	Методы установки значений и вывода значений на экран (использовать потоковый ввод/вывод). 
// 	Static-счетчик количества существующих объектов класса.
// 	В подходящих для этого методах, используйте параметры по умолчанию.
// 	Используйте в конструкторах список инициализации. 
#pragma once

#include <cstring>		// strlen()
#include <cctype>		// isdigit()
#include <cstdlib>		// atoi()
#include <string>		// string

// #include <iostream>

namespace fractionErrors 
{
	const int NO_ERRORS = 0;
	const int SET_ZERO_DENOMINATOR_ERROR = -1;
	const int GIVEN_NULL_POINTER = -2;
}

class Fraction
{
private:
	int numerator;
	int denominator;
	static unsigned int count;
	static int err;

	int reduction();
	static int GCD(int a, int b)
	{
		int r = a%b;
		while (r)
		{
			a = b;
			b = r;
			r = a%b;
		}
		return b;
	}
	static int LCM(int a, int b)
	{
		return a*b/GCD(a,b);
	}


	static int ITS(char* s, int n)
	{
		int i, sign;
		if ((sign = n) < 0)    
			n = -n;     
		i = 0;
		do 
		{               
			s[i++] = n % 10 + '0';   
		} while ((n /= 10) > 0);     
		if (sign < 0)
			s[i++] = '-';
		int r = i;
		s[i--] = '\0';
		int j = 0;
		char c;
		while(j<i)
		{
			c = s[j];
			s[j++] = s[i];
			s[i--] = c;
		}
		return r;
	}


public:
	Fraction(const int numerator=0, const int denominator=1);
	Fraction(const char* str);
	// Fraction(const &string);
	Fraction(const Fraction &other);
	Fraction(const Fraction *other);
	~Fraction();

	static unsigned int getObjectsCount() {return count;}
	static int getLastError() {return err;}
	
	int setFraction(int numerator=0, int denominator=1);

	std::string toStr();
	double toDouble();
	

	Fraction add(const Fraction &other);
	Fraction sub(const Fraction &other);
	Fraction mul(const Fraction &other);
	Fraction div(const Fraction &other);
};

// int Fraction::GCD(int a, int b)
// {
// 	int r = a%b;
// 	while (r)
// 	{
// 		a = b;
// 		b = r;
// 		r = a%b;
// 	}
// 	return b;
// }

// int Fraction::LCM(int a, int b)
// {
// 	return a*b/GCD(a,b);;
// }

// int Fraction::ITS(char* s, int n)
// {
// 	int i, sign;
// 	if ((sign = n) < 0)    
// 		n = -n;     

// 	std::cout << "ITS" << sign << n << std::endl;           
// 	i = 0;
// 	do 
// 	{               
// 		s[i++] = n % 10 + '0';   
// 	} while ((n /= 10) > 0);     
// 	if (sign < 0)
// 		s[i++] = '-';
// 	int r = i;
// 	s[i--] = '\0';
// 	int j = 0;
// 	char c;
// 	while(j<i)
// 	{
// 		c = s[j];
// 		s[j++] = s[i];
// 		s[i++] = c;
// 	}
// 	return r;
// }