#ifndef BEVERAGE_H_
#define BEVERAGE_H_
#include <iostream>
#include <string>
#include "Item.h"
#include "rounding.h"


using namespace std;
class Beverage : public Item
{
private:
	float abv;
	int volume;
public:
	bool isAlcoholic();
	string toString();
	Beverage(string, float, int, int, float);
};
#endif
