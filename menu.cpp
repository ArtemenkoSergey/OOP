#include "menu.h"

MenuItem::MenuItem(const char* tMessage, const int tReturnCode, const char tActivationChar)\
	:message(tMessage),returnCode(tReturnCode),activationChar(tActivationChar)
{}

MenuItem::~MenuItem()
{
	// delete message;
}

int MenuItem::getReturnCode() const
{
	return returnCode;
}

char MenuItem::getActivationChar() const
{
	return activationChar;
}

void MenuItem::show() const
{
	std::cout << ' ' << activationChar << " : " << message << std::endl;
}

SimpleMenu::SimpleMenu(int tSize):size(tSize)
{
	itemCount = 0;
	menuItems = new MenuItem*[size];
	for (int i = 0; i < size; ++i)
		menuItems[i] = NULL;
}

SimpleMenu::~SimpleMenu()
{
	for (int i = 0; i < itemCount; ++i)
		delete menuItems[i];
	delete[] menuItems;
}

int SimpleMenu::addMenuItem(const char* tMessage, const int tReturnCode, const char tActivationChar)
{
	if (itemCount >= size)
		return MENU_OVERFLOW_ERROR;
	menuItems[itemCount++] = new MenuItem(tMessage, tReturnCode, toupper(tActivationChar));
	return NO_ERRORS;
}

int SimpleMenu::execute() const
{
	char inputChar;
	while (1)
	{
		show();
		std::cin >> inputChar;
		inputChar = toupper(inputChar);
		for (int i = 0; i < itemCount; ++i)
			if (inputChar == menuItems[i]->getActivationChar())
				return menuItems[i]->getReturnCode();

		std::cout << "неверно введен символ выбора. повторите выбор пункта меню" << std::endl;
	}
}

void SimpleMenu::show() const
{
	for (int i = 0; i < itemCount; ++i)
		menuItems[i]->show();
}

