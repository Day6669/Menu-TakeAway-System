#ifndef ITEMLIST_H_
#define ITEMLIST_H_
#include <vector>
#include <string>
#include "Item.h"

using namespace std;
class ItemList 
{
public:
	vector <Item*> items;
	virtual string toString() = 0;
};
#endif