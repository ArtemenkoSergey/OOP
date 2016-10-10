#include <cstdlib>		// rand()
#include <iostream>
#include <ctime>

#include "fraction.h"
#include "conteiner.h"

int main(int argc, char const *argv[])
{
	srand (time(NULL));
	int l = 20;
	Conteiner A(l);
	Fraction *f;
	int n,d,err = 1;
	for (int i = 0; i < l; ++i)
	{
		f = new Fraction();
		while (err != 0)
		{
			n = rand()%100 - 50;
			d = rand()%100 - 50;
			std::cout << n << "/" << d << std::endl;
			err = f->setFraction(n,d);
		}
		A.addItem(f);
		err = 1;
	}

	A.showAll();

	std::cout << std::endl << "count " << Fraction::getCount() << std::endl;
	return 0;
}