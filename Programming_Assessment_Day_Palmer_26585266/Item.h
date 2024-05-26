#ifndef ITEM_H_
#define ITEM_H_
#include <string>

using namespace std;
class Item
{
public:
	int calories;
	string name;
	float  price;
	string toString();
	string ID;	
	Item(string, float, int);
};
#endif
