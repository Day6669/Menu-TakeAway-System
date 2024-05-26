#ifndef APPETISER_H_
#define APPETISER_H_
#include <string>
#include <iostream>
#include "Item.h"
#include "rounding.h"

using namespace std;

class Appetiser : public Item
{
private:
	bool shareable;
	bool twoforOne;
public:
	bool isTwoForOne();
	string toString();
	Appetiser(string , float, int, bool, bool);
};
#endif