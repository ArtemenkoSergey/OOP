#pragma once
#include <cstring>		// memcpy()
#include <iostream>		// cout
#include <iomanip>		// setw()


// #define NO_ERRORS 0
#define DELETE_NULL_PTR_ERROR -2
#define NOT_FIND_FREE_ERROR -1


#include "fraction.h"

class Conteiner
{
private:
	Fraction** Array;
	int lenght;
	
	void reSize();
	int findFree();
public:
	Conteiner(int tLenght=10);
	~Conteiner();

	int addItem(Fraction* newItem);
	Fraction* getItem(int index);
	int delItem(int index);

	int getLenght() const;
	void showAll() const;
};