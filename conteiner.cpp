#include "conteiner.h"




Conteiner::Conteiner(int tLenght):lenght(10)
{
	if (tLenght > 0)
		lenght = tLenght;
	Array = new Fraction*[lenght];
	for (int i = 0; i < lenght; ++i)
		Array[i] = NULL;
}

Conteiner::~Conteiner()
{
	for (int i = 0; i < lenght; ++i)
	{
		if (Array[i]!=NULL)
		{
			delete Array[i];
		}
	}
	delete[] Array;
}

int Conteiner::addItem(Fraction* newItem)
{
	int index = findFree();
	if (index == NOT_FIND_FREE_ERROR)
	{
		reSize();
		index = findFree();
	}
	if (index>=0)
		Array[index] = newItem;
	// std::cout << "item add " << index << std::endl;
	return index;
}

Fraction* Conteiner::getItem(int index)
{
	if (index >= 0 && index < lenght)
	{
		return Array[index];
	}
	return NULL;
}

int Conteiner::delItem(int index)
{
	if (Array[index]!=NULL)
	{
		delete Array[index];
		Array[index] = NULL;
		return NO_ERRORS;
	}
	return DELETE_NULL_PTR_ERROR;
}

int Conteiner::findFree()
{
	int index = 0;
	while(index<lenght && Array[index]!=NULL) index++;
	if (index < lenght)
		return index;
	return NOT_FIND_FREE_ERROR;
}

void Conteiner::reSize()
{
	int newLenght = lenght*2;
	Fraction** newArray = new Fraction*[newLenght];
	memcpy(newArray, Array, sizeof(Fraction*)*lenght);
	delete[] Array;

	Array = newArray;
	lenght = newLenght;
}

void Conteiner::showAll() const
{
	for (int i = 0; i < lenght; ++i)
	{
		std::cout << std::setw(5) << i << " : ";
		if (Array[i]!=NULL)
			Array[i]->toStr();
		else
			std::cout << "пусто";
		std::cout << std::endl;
	}
}

int Conteiner::getLenght() const
{
	return lenght;
}