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
#include <iostream>

#define NO_ERRORS 0
#define SET_ZERO_DENOMINATOR_ERROR -1

class Fraction
{
private:
	unsigned int numerator;
	unsigned int denominator;
	char sign;
	static unsigned int count;

	int reduction();

public:
	Fraction(int numerator=0, int denominator=1);
	Fraction(const Fraction &other);
	~Fraction();

	static unsigned int getCount() {return count;}
	int setFraction(int numerator=0, int denominator=1);
	
	// int getStr();
	double getDouble();
	
	void input();
	void show();

	int add(const Fraction &other);
	int sub(const Fraction &other);
	int mul(const Fraction &other);
	int div(const Fraction &other);
};

// static unsigned int Fraction::getCount()
// {
// 	return count;
// }