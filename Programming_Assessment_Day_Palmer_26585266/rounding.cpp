#include "rounding.h"
// everytime it prints a total this rounds the number
string RoundString(double value){
	ostringstream ss;
	ss.precision(2);
	ss << fixed << value;
	string s = ss.str();
	return s;
}