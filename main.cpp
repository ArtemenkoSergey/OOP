#include "fraction.h"

int main(int argc, char const *argv[])
{
	Fraction a(1,2), b(1,3);
	Fraction c(a);
	a.show();
	b.show();

	a.sub(b);
	a.show();

	
	c.show();

	a.mul(b);
	b.div(c);
	a.show();
	b.show();

	return 0;
}