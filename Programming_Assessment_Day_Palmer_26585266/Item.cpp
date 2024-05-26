#include "Item.h"
#include "rounding.h"
// this is called for each of its children and assigns their variables
Item::Item(string name_in,float price_in,int calories_in){
	name = name_in;
	price = price_in;
	calories = calories_in;
}
// returns the string of the item
string Item::toString()
{
	return (name + ": $" + RoundString(price) + "," + to_string(calories) + " cal");
}