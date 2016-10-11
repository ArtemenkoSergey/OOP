#pragma once
#include <iostream>		// cin cout
#include <string>		// string
#include <cctype>		// toupper


#define NO_ERRORS 0
#define MENU_OVERFLOW_ERROR -1



class MenuItem
{
protected:
	const std::string message;
	const int returnCode;
	const char activationChar; 
public:
	MenuItem(const char* tMessage, const int tReturnCode, const char tActivationChar);
	~MenuItem();
	int getReturnCode() const;
	char getActivationChar() const;
	void show() const;
};


class SimpleMenu
{
protected:
	const int size;
	int itemCount;
	MenuItem** menuItems;
	void show() const;
public:
	SimpleMenu(const int tSize = 5);
	~SimpleMenu();
	
	int addMenuItem(const char* tMessage, const int tReturnCode, const char tActivationChar);
	int execute() const;
};