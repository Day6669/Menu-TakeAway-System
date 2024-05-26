#include "Appetiser.h"

using namespace std; 

// this constructor is used to assign the variables
Appetiser::Appetiser(string name_in, float price_in,int calories_in,bool shareable_in,bool twoforOne_in) : Item(name_in,price_in,calories_in)
{
	shareable = shareable_in;
	ID = "appetiser";
	twoforOne = twoforOne_in;
}
// uses an if statement to assign output to if the value is a 2-4-1 or a shareable and formats the text
// if it isnt then return the text as usual
string Appetiser::toString() {
	if (shareable) {
		return (name + ": $" + RoundString(price) + "," + to_string(calories) + " cal (shareable)");
	}
	else if (twoforOne) {
		return (name + ": $" + RoundString(price) + ", " + to_string(calories) + "cal (2-4-1)");
	}
	else {
		return (name + ": $" + RoundString(price) + ", " + to_string(calories));
	}
	

}
// this is a getter for TwoForOne since it is private
bool Appetiser::isTwoForOne() 
{
	return twoforOne;
}