#include "Beverage.h"


// same usage of constructor but for beverage instead
Beverage::Beverage(string name_in, float price_in, int calories_in, int volume_in, float abv_in) : Item(name_in, price_in, calories_in)
{
	ID = "beverage";
	abv = abv_in;
	volume = volume_in;
}
// finds out if the beverage is alcoholic or not
bool Beverage::isAlcoholic()
{
	if (abv > 0) {
		return true;
	}
	else {
		return false;
	}
};
// uses toString to format the output text to show beverage percentage if alcoholic
string Beverage::toString() {
	if (abv)
	{
		return (name + ": $" + RoundString(price) + ", " + to_string(calories) + " cal (" + RoundString(volume) + "ml," + RoundString(abv) + "% abv)");
	}
	else
	{
		return (name + ": $" + RoundString(price) + ", " + to_string(calories) + " cal (" + RoundString(volume) + "ml)");
	}
}