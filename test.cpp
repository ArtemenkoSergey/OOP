#include <iostream>		// cout, cin
#include "myString.h"

int main(int argc, char const *argv[])
{
	myString A = "qwer";
	myString B = "qwer";
	A.insert(0, "QWEI");
	std::cout << A.strAddr() << std::endl;
	return 0;
}
