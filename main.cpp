#include <cstdlib>		// rand()
#include <iostream>
#include <ctime>

#include "fraction.h"
#include "conteiner.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
	// srand (time(NULL));
	// int l = 20;
	// Conteiner A(l);
	// Fraction *f;
	// int n,d,err = 1;
	// for (int i = 0; i < l; ++i)
	// {
	// 	f = new Fraction();
	// 	while (err != 0)
	// 	{
	// 		n = rand()%100 - 50;
	// 		d = rand()%100 - 50;
	// 		std::cout << n << "/" << d << std::endl;
	// 		err = f->setFraction(n,d);
	// 	}
	// 	A.addItem(f);
	// 	err = 1;
	// }

	// A.showAll();

	// std::cout << std::endl << "count " << Fraction::getCount() << std::endl;

	Conteiner A;
	Fraction* f; 
	const int mainMenu_action_add = 1;
	const int mainMenu_action_view = 2;
	const int mainMenu_action_edit = 3;
	const int mainMenu_action_del = 4;
	const int action_exit = 0;

	SimpleMenu mainMenu(5);
	mainMenu.addMenuItem("Добавить новый объект...", mainMenu_action_add, '1');
	mainMenu.addMenuItem("Просмотреть имеющиеся объекты", mainMenu_action_view, '2');
	mainMenu.addMenuItem("Редактировать имеющийся объект...", mainMenu_action_edit, '3');
	mainMenu.addMenuItem("Удалить объект...", mainMenu_action_del, '4');
	mainMenu.addMenuItem("Выход из программы", action_exit, 'E');
	
	const int addMenu_action_create_default = 1;
	const int addMenu_action_create_rnd = 4;
	const int addMenu_action_copy =	2;
	const int addMenu_action_input = 3;

	SimpleMenu subMenuAdd(5);
	subMenuAdd.addMenuItem("Создать объект по умолчанию", addMenu_action_create_default, '1');
	subMenuAdd.addMenuItem("Скопировать объект", addMenu_action_copy, '2');
	subMenuAdd.addMenuItem("Ввести значения с стандартного ввода", addMenu_action_input, '3');
	subMenuAdd.addMenuItem("Сгенерировать случайные объекты", addMenu_action_create_rnd, '4');
	subMenuAdd.addMenuItem("Вернутся в предидущее меню", action_exit, 'E');


	int selected, subselected;
	do
	{
		selected = mainMenu.execute();
		switch (selected){
			mainMenu_action_add:
					std::cuot << "Выберете способ добавления объекта:" << std::endl;
					subselected = subMenuAdd.execute();
					switch (subselected){
						addMenu_action_create_default: 
								f = new Fraction();
								A.addItem(f);
								break;
						addMenu_action_copy:
								int index = 0;
								// выбор копируемого элемента.
								f = new Fraction(A.getItem(index));
								A.addItem(f);
								break;
						addMenu_action_input:
								f = new Fraction();
								f->input();
								A.addItem(f);
								break;
						addMenu_action_create_rnd:
								// ввод количества генерируемых объектов
								f = new Fraction();
								A.addItem(f);
								break;
					}
					break;

			default
				break;
		}
		
	}
	while (selected != 0);
	return 0;
}