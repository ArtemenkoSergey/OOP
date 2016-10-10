// Вариант № 5. Дробь.
// Класс хранит значение дроби. Предусмотреть метод сокращения дроби, умножения и деления на другую дробь (передавать как параметры функции).

// Класс должен включать в себя:
// 	Данные-члены, типы и количество которых хорошо подходят для хранения и представления соответствующих значений.
// 	Конструктор по умолчанию, конструктор с параметрами (возможно, не один), конструктор копирования и деструктор. 
// 	Методы установки значений и вывода значений на экран (использовать потоковый ввод/вывод). 
// 	Static-счетчик количества существующих объектов класса.
// 	В подходящих для этого методах, используйте параметры по умолчанию.
// 	Используйте в конструкторах список инициализации. 

class Fraction
{
private:
	long int numerator;
	long int denominator;
	char sign;
	static unsigned int counter;
public:
	Fraction();
	Fraction(long int numerator, long int denominator=1);
	Fraction(double);
	~Fraction();

	int setFraction(long int numerator, long int denominator);
	int setFraction(double);
	int getStr();
	double getDouble();
	
	int input();
	int show();

	int reduction();

	int add(Fraction other);
	int sub(Fraction other);
	int mul(Fraction other);
	int div(Fraction other);
};
