#include "MainCourse.h"
// main course
MainCourse::MainCourse(string name_in, float price_in, int calories_in) : Item(name_in, price_in, calories_in)
{
	ID = "MainCourse";
}