#ifndef MENU_H_
#define MENU_H_
#include <string>
#include "ItemList.h"
#include <fstream>
#include <iostream>

using namespace std;
class Menu : public ItemList
{
public:
	string toString();
	Menu(string);
	Item* find(int);
	string filename;
	void load();
};
#endif