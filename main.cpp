
#include <iostream>		// cout, cin
#include <iomanip>		// setw()
#include <stdexcept>	// out_of_range()


// #include "fraction.h"
// #include "conteiner.h"
// #include "menu.h"
#include "myString.h"

void mainMenu(myString** A, int len);
void createNewStringMenu(myString** A, int len);

void changeStringMenu(myString** A, int len);
void changeStringAppendMenu(myString** A, int len, int index);
void changeStringAssignMenu(myString** A, int len, int index);
void changeStringInsertMenu(myString** A, int len, int index);
void changeStringReplaceMenu(myString** A, int len, int index);

void callMetodMenu(myString** A, int len);
int selectStringMenu(myString** A, int len);

int main(int argc, char const *argv[])
{
	int len = 0;
	if (argc>1)
		len = atoi(argv[1]);

	if (len < 5) 
		len = 5;
	
	myString** A = new myString* [len];

	A[0] = new myString("qwer");
	A[1] = new myString("asdf");
	A[2] = new myString("zxzxzxzxzx");

	// std::cout << myString::getObjCount() << std::endl;
	mainMenu(A, len);

	// changeStringMenu(A, len);

	for (int i = 0; i < len; ++i)
	{
		if (A[i]!=NULL)
			delete A[i];
	}
	delete[] A;
	return 0;
}


void mainMenu(myString** A, int len)
{
	char ch;
	int s;
	do
	{
		std::cout << "1. Создать новую строку..." << std::endl;
		std::cout << "2. Показать массив строк" << std::endl;
		std::cout << "3. Изменить строку..." << std::endl;
		std::cout << "4. Вызвать метод для строки..." << std::endl;
		std::cout << "5. Удалить строку..." << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
			case '1':
				createNewStringMenu(A,len);
				break;
			case '2':
				for (int i = 0; i < len; ++i)
				{
					std::cout << std::setw(5) << i << " : ";
					if (A[i] != NULL)
						std::cout << A[i]->strAddr() << std::endl;
					else
						std::cout << "Пустой элемент" << std::endl;
				}
				break;
			case '3':
				changeStringMenu(A, len);
				break;
			case '4':
				callMetodMenu(A, len);
				break;
			case '5':
				s = selectStringMenu(A, len);
				if (s > 0 && A[s]!=NULL)
				{
					delete A[s];
					A[s]=NULL;
				}
				break;
			case 'Q': case 'q':
				break;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
	}while(ch != 'Q' && ch != 'q');
}

void createNewStringMenu(myString** A, int len)
{
	int i = 0;
	while(A[i]!=NULL && i < len)
		i++;
	char ch;
	int s;
	while(i < len)
	{
		std::cout << std::endl;
		std::cout << "1. Ввести с клавиатуры" << std::endl;
		std::cout << "2. Скопировать другую строку" << std::endl;
		std::cout << "3. Скопировать часть другой строки" << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		switch (ch)
		{
			case '1':
				char buffer[1024];
				std::cout << "Введите строку: " << std::endl;
				std::cin.getline(buffer, sizeof(buffer));
				A[i] = new myString(buffer);
				break;
			case '2':
				s = selectStringMenu(A, len);
				// std::cout << "s " << s << std::endl;
				if (s >= 0)
					A[i] = new myString(*(A[s]));
				break;
			case '3':
				s = selectStringMenu(A, len);
				// std::cout << "s " << s << std::endl;
				if (s >= 0)
				{
					do
					{
						size_t pos, len;
						std::cout << "Введите начальную позицию и длинну копируемой части: " << std::endl;
						std::cin >> pos >> len;
						std::cin.ignore();
						// std::cout << "pos " << pos << " len " << len << std::endl;
						try
						{
							A[i] = new myString(*(A[s]), pos, len);
						}
						catch (std::out_of_range ex)
						{
							std::cerr << "Out of range error: " << ex.what() << std::endl;
						}

					}while(A[i]==NULL);

				}
				break;
			case 'Q': case 'q':
				return;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
		while(A[i]!=NULL && i < len)
			i++;
	}
	std::cout << "Нет места для новой строки" << std::endl;
}

void changeStringMenu(myString** A, int len)
{
	char ch;
	std::cout << "Выберете изменяемую строку:" << std::endl;
	int t;
	int s = selectStringMenu(A, len);
	while(s >= 0)
	{
		std::cout << std::endl;
		std::cout << "1. Добавить к строке..." << std::endl;
		std::cout << "2. Присвоить значение строке..." << std::endl;
		std::cout << "3. Вставить в строку..." << std::endl;
		std::cout << "4. Заменить в строке..." << std::endl;
		std::cout << "5. Выбрать другую строку" << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		switch (ch)
		{
			case '1':
				changeStringAppendMenu(A, len, s);
				break;
			case '2':
				changeStringAssignMenu(A, len, s);
				break;
			case '3':
				changeStringInsertMenu(A, len, s);
				break;
			case '4':
				changeStringReplaceMenu(A, len, s);
				break;
			case '5':
				t = selectStringMenu(A, len);
				if (t >= 0 )
					s = t;
				break;
			case 'Q': case 'q':
				return;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Выбранная строка после изменения:" << std::endl;
		std::cout << A[s]->strAddr() << std::endl;
	}
}

void callMetodMenu(myString** A, int len)
{
	char ch;
	std::cout << "Выберете строку:" << std::endl;
	int s = selectStringMenu(A, len);
	while(s >= 0)
	{
		std::cout << std::endl;
		std::cout << "1. size_t strSize() const" << std::endl;
		std::cout << "2. void clear()" << std::endl;
		std::cout << "3. bool empty() const" << std::endl;
		std::cout << "4. void swap(myString& tStr)" << std::endl;
		std::cout << "5. int count(const myString& subStr, size_t start=0, size_t end=0) const" << std::endl;
		std::cout << "6. int count(const char ch, size_t start=0, size_t end=0) const;" << std::endl;
		std::cout << "7. int find(const myString& subStr, size_t start=0, size_t end=0) const;" << std::endl;
		std::cout << "8. int find(const char ch, size_t start=0, size_t end=0) const;" << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		int t, r;
		char a;
		size_t start, end;
		switch (ch)
		{
			case '1':
				std::cout << "Количество символов занимаемых строкой: "<< A[s]->strSize() << std::endl;
				return;
			case '2':
				A[s]->clear();
				std::cout << "Строка после работы метода: " << A[s]->strAddr() << std::endl;
				return;
			case '3':
				if (A[s]->empty())
					std::cout << "Строка пустая" << std::endl;
				else
					std::cout << "Строка не пустая: " << A[s]->strAddr() << std::endl;
				return;
			case '4':
				t = selectStringMenu(A, len);
				A[s]->swap(*(A[t]));
				std::cout << "Строка 1 после работы метода: " << A[s]->strAddr() << std::endl;
				std::cout << "Строка 2 после работы метода: " << A[t]->strAddr() << std::endl;
				return;
			case '5':
				do
				{
					t = selectStringMenu(A, len);
					try
					{
						r = A[s]->count(*(A[t]));
						break;
					}
					catch(std::invalid_argument ex)
					{
						std::cerr << "Invalid argument error: " << ex.what() << std::endl;
					}
				}while(1);
				std::cout << "Подстрока: " << A[t]->strAddr() << std::endl;
				std::cout << "в строке: " << A[s]->strAddr() << std::endl;
				std::cout << "Найдена " << r << " раз" << std::endl;
				return;
			case '6':
				do
				{
					std::cout << "Введите символ: ";
					std::cin >> a;
					std::cin.ignore();
					std::cout << "Введите позиции начала и окончания поиска: ";
					std::cin >> start >> end;
					std::cin.ignore();
					try
					{
						r = A[s]->count(a, start, end);
						break;
					}
					catch(std::out_of_range ex)
					{
						std::cerr << "Out of range error: " << ex.what() << std::endl;
					}
				}while(1);
				std::cout << "Символ " << a <<  " в строке: " << A[s]->strAddr() << std::endl;
				std::cout << "Найден " << r << " раз" << std::endl;
				return;
			case '7':
				do
				{
					t = selectStringMenu(A, len);
					try
					{
						r = A[s]->find(*(A[t]));
						break;
					}
					catch(std::invalid_argument ex)
					{
						std::cerr << "Invalid argument error: " << ex.what() << std::endl;
					}
				}while(1);
				std::cout << "Подстрока: " << A[t]->strAddr() << std::endl;
				std::cout << "в строке: " << A[s]->strAddr() << std::endl;
				if ( r >= 0)
					std::cout << "Найдена на позиции " << r << std::endl;
				else
					std::cout << "Не найдена" << std::endl;
				return;
			case '8':
				std::cout << "Введите символ: ";
				std::cin >> a;
				std::cin.ignore();
				std::cout << "Введите позиции начала и окончания поиска: ";
				std::cin >> start >> end;
				std::cin.ignore();
				r = A[s]->find(a, start, end);
				std::cout << "Символ " << a <<  " в строке: " << A[s]->strAddr() << std::endl;
				if ( r >= 0)
					std::cout << "Найден на позиции " << r << std::endl;
				else
					std::cout << "Не найден" << std::endl;
				return;
			case 'Q': case 'q':
				return;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
	}
}
int selectStringMenu(myString** A, int len)
{
	int index = 0;
	char ch;
	do
	{
		std::cout << std::setw(5) << 'P' << " Предидущие 10 " << std::endl;
		for (int i = 0; i < 10 && i < index+len; ++i)
		{
			std::cout << std::setw(5) << i << " : ";
			if (A[i] != NULL)
				std::cout << A[i+index]->strAddr() << std::endl;
			else
				std::cout << "Пустой элемент" << std::endl;
		}
		std::cout << std::setw(5) << 'N' << " Следующие 10 " << std::endl;
		std::cout << std::setw(5) << 'Q' << " Выход " << std::endl;
		std::cin >> ch;
		switch (ch)
			{
				case '0': case '1': case '2': case '3':
				case '4': case '5': case '6': case '7':
				case '8': case '9':
					if (A[index+ch-'0']!=NULL)
						return index+ch-'0';
					std::cout << "Нельзя выбирать пустой элемент" << std::endl;
					break;
				case 'P': case 'p':
					if (index>9)
						index-=10;
					else
						std::cout << "Q. Выход" << std::endl;
					break;
				case 'N': case 'n':
					if (len - index > 9)
						index+=10;
					break;
				case 'Q': case 'q':
					return -1;
				default:
					std::cout << "введено :" << ch << std::endl;
			}
	}while(1);
}

void changeStringAppendMenu(myString** A, int len, int index)
{
	char ch;
	int s;
	while(1)
	{
		std::cout << std::endl;
		std::cout << "Выбранная строка:" << std::endl;
		std::cout << A[index]->strAddr() << std::endl;
		std::cout << std::endl;
		std::cout << "1. Добавить символ" << std::endl;
		std::cout << "2. Добавить строку введенную со стандартного ввода" << std::endl;
		std::cout << "3. Добавить строку из массива строк" << std::endl;
		std::cout << "4. Добавить часть строки из массива строк" << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		switch (ch)
		{
			case '1':
				char t;
				std::cout << "Введите добавляемый символ: ";
				std::cin >> t;
				std::cin.ignore();
				A[index]->append(t);
				return;
			case '2':
				char buffer[1024];
				std::cout << "Введите добавляемую строку: " << std::endl;
				std::cin.getline(buffer, sizeof(buffer));
				A[index]->append(buffer);
				return;
			case '3':
				s = selectStringMenu(A, len);
				if (s >= 0)
					A[index]->append(*(A[s]));
				return;
			case '4':
				s = selectStringMenu(A, len);
				if (s >= 0)
				{
					do
					{
						size_t pos, len;
						std::cout << "Введите начальную позицию и длинну добавляемой части: " << std::endl;
						std::cin >> pos >> len;
						std::cin.ignore();
						// std::cout << "pos " << pos << " len " << len << std::endl;
						try
						{
							A[index]->append(*(A[s]), pos, len);
							break;
						}
						catch (std::out_of_range ex)
						{
							std::cerr << "Out of range error: " << ex.what() << std::endl;
						}

					}while(1);
				}
				return;
			case 'Q': case 'q':
				return;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
	}
}
void changeStringAssignMenu(myString** A, int len, int index)
{
	char ch;
	int s;
	while(1)
	{
		std::cout << std::endl;
		std::cout << "Выбранная строка:" << std::endl;
		std::cout << A[index]->strAddr() << std::endl;
		std::cout << std::endl;
		std::cout << "1. Присвоить значение символа" << std::endl;
		std::cout << "2. Присвоить значение строки введенной с клавиатуры" << std::endl;
		std::cout << "3. Присвоить значение другой строки..." << std::endl;
		std::cout << "4. Присвоить значение части другой строки..." << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		switch (ch)
		{
			case '1':
				char t;
				std::cout << "Введите символ: ";
				std::cin >> t;
				std::cin.ignore();
				int n;
				std::cout << "Введите количество симвов: ";
				std::cin >> n;
				std::cin.ignore();
				A[index]->assign(t,n);
				return;
			case '2':
				char buffer[1024];
				std::cout << "Введите строку: " << std::endl;
				std::cin.getline(buffer, sizeof(buffer));
				A[index]->assign(buffer);
				return;
			case '3':
				s = selectStringMenu(A, len);
				if (s >= 0)
					A[index]->assign(*(A[s]));
				return;
			case '4':
				s = selectStringMenu(A, len);
				if (s >= 0)
				{
					do
					{
						size_t pos, len;
						std::cout << "Введите начальную позицию и длинну добавляемой части: " << std::endl;
						std::cin >> pos >> len;
						std::cin.ignore();
						// std::cout << "pos " << pos << " len " << len << std::endl;
						try
						{
							A[index]->assign(*(A[s]), pos, len);
							break;
						}
						catch (std::out_of_range ex)
						{
							std::cerr << "Out of range error: " << ex.what() << std::endl;
						}

					}while(1);
				}
				return;
			case 'Q': case 'q':
				return;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
	}
}
void changeStringInsertMenu(myString** A, int len, int index)
{
	char ch;
	int s;
	size_t pos;
	while(1)
	{
		std::cout << std::endl;
		std::cout << "Выбранная строка:" << std::endl;
		std::cout << A[index]->strAddr() << std::endl;
		std::cout << std::endl;
		
		std::cout << "Введите позицию для вставки " << std::endl;
		std::cin >> pos;
		std::cin.ignore();

		std::cout << std::endl;
		std::cout << "1. Вставить символы" << std::endl;
		std::cout << "2. Вставить строку введенную с клавиатуры" << std::endl;
		std::cout << "3. Вставить другую строку..." << std::endl;
		std::cout << "4. Вставить часть другой строки" << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		switch (ch)
		{
			case '1':
				char t;
				std::cout << "Введите символ: ";
				std::cin >> t;
				std::cin.ignore();
				int n;
				std::cout << "Введите количество симвов: ";
				std::cin >> n;
				std::cin.ignore();
				A[index]->insert(pos, t, n);
				return;	
			case '2':
				char buffer[1024];
				std::cout << "Введите строку: " << std::endl;
				std::cin.getline(buffer, sizeof(buffer));
				A[index]->insert(pos, buffer);
				return;
			case '3':
				s = selectStringMenu(A, len);
				if (s >= 0)
					A[index]->insert(pos, *(A[s]));
				return;
			case '4':
				s = selectStringMenu(A, len);
				if (s >= 0)
				{
					do
					{
						size_t pos, len;
						std::cout << "Введите начальную позицию и длинну добавляемой части: " << std::endl;
						std::cin >> pos >> len;
						std::cin.ignore();
						// std::cout << "pos " << pos << " len " << len << std::endl;
						try
						{
							A[index]->insert(pos, *(A[s]), pos, len);
							break;
						}
						catch (std::out_of_range ex)
						{
							std::cerr << "Out of range error: " << ex.what() << std::endl;
						}

					}while(1);
				}
				return;
			case 'Q': case 'q':
				return;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
	}
}
void changeStringReplaceMenu(myString** A, int len, int index)
{
	char ch;
	while(1)
	{
		std::cout << std::endl;
		std::cout << "Выбранная строка:" << std::endl;
		std::cout << A[index]->strAddr() << std::endl;
		std::cout << std::endl;
		std::cout << "1. Заменить символ" << std::endl;
		std::cout << "2. Заменить подстроку" << std::endl;
		std::cout << "3. Заменить выбранную подстроку на дгую подстроку" << std::endl;
		std::cout << "Q. Выход" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		switch (ch)
		{
			case '1':
				char o;
				std::cout << "Введите заменяемый символ: ";
				std::cin >> o;
				std::cin.ignore();
				char n;
				std::cout << "Введите символ для замены: ";
				std::cin >> n;
				std::cin.ignore();
				int mc;
				std::cout << "Введите количество замен (0 - заменить все): ";
				std::cin >> mc;
				std::cin.ignore();
				A[index]->replace(o, n, mc);
				return;
			case '2':
				char bufferO[1024];
				char bufferN[1024];
				std::cout << "Введите заменяемую строку: " << std::endl;
				std::cin.getline(bufferO, sizeof(bufferO));
				std::cout << "Введите строку для замены: " << std::endl;
				std::cin.getline(bufferN, sizeof(bufferN));
				int mC;
				std::cout << "Введите количество замен (0 - заменить все): ";
				std::cin >> mC;
				std::cin.ignore();
				A[index]->replace(bufferO, bufferN, mC);
				return;
			case '3':
				int s1, s2;
				std::cout << "Выберете заменяемую строку: " << std::endl;
				s1 = selectStringMenu(A, len);
				std::cout << "Выберете строку для замены: " << std::endl;
				s2 = selectStringMenu(A, len);
				if (s1 >= 0 && s2 >= 0)
					A[index]->replace(*(A[s1]),*(A[s2]));
				return;
			case 'Q': case 'q':
				return;
			default:
				std::cout << "введено :" << ch << std::endl;
		}
	}
}