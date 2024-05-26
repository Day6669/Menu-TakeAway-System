#ifndef ORDER_H_
#define ORDER_H_
#include "ItemList.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include "Appetiser.h"
#include "Beverage.h"

using namespace std;

class Order : public ItemList
{
private:
	int total;
	float savings;
public:
	float calculateTotal();
	void printReceipt();
	Order();
	string toString();
	void add(Item*);
	void remove(int);
	Item* getname(int);
	int discount();
	int salePrice();
};
#endif
