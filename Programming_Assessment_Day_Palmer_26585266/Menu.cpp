#include "Menu.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"

// fetches the filename
Menu::Menu(string csvmenu)
{
	filename = csvmenu;
	load();
}
// loads the menu from the filename
void Menu::load() 
{
	string line;
	ifstream menufile(filename);
	while(getline(menufile,line)) // reads the menufile line by line
	{
		string name;
		vector <string> parameters;
		bool shareable;
		bool twoforOne;
		// isolates appetisers
		if (line[0] == 'a')
		{

			for (int i = 0; i < line.size(); i++) // loops through the menu item separating the components into parameters
			{
				if (line[i] == ',')
				{
					parameters.push_back(name); // separates the parameters
					name = "";
				}
				else {
					name += line[i];
				}
			}
			// convert shareable from string to bool
			if (parameters[4] == "y") {
				shareable = true;
			}
			else 
			{
				shareable = false;
			}
			// converts 2-4-1 into bool
			if (parameters[5] == "n") {
				twoforOne = false;
			}
			else
			{
				twoforOne = true;
			}
			// creates the list for appetisers and gives the variables the appropriate type
			Item* t = new Appetiser(parameters[1],stof(parameters[2]), stoi(parameters[3]), shareable, twoforOne);
			items.push_back(t);
		}
		//isolates beverages
		if (line[0] == 'b')
		{
			line += ','; // add the comma to signify the end of the item
			for (int i = 0; i < line.size(); i++) // loops through the menu item separating the components into parameters
			{
				if (line[i] == ',')
				{
					parameters.push_back(name); // separates the parameters
					name = "";
				}
				else {
					name += line[i];
				}
			}

			// creates the list for beverages and gives the variables the appropriate type
			Item* t = new Beverage(parameters[1], stof(parameters[2]), stoi(parameters[3]), stof(parameters[6]), stoi(parameters[7]));
			items.push_back(t);
		}
		// isolates menu
		if (line[0] == 'm')
		{

			for (int i = 0; i < line.size(); i++)  // loops through the menu item separating the components into parameters
			{
				if (line[i] == ',') // add the comma to signify the end of the item
				{
					parameters.push_back(name); // separates the parameters
					name = "";
				}
				else {
					name += line[i];
				}
			}
			// creates the list for main course and gives the variables the appropriate type
			Item* t = new MainCourse(parameters[1], stof(parameters[2]), stoi(parameters[3]));
			items.push_back(t);
		}
	}
}
// displays the menu in an attractive format
string Menu::toString() {
	string output = " ";
	output += "--------------Appetisers--------------\n";
	int num = 1;
	for( Item* item : items) 
	{
		if (item->ID == "appetiser")
		{
			output += "(" + to_string(num) + ") " + ((Appetiser*)item)->toString() + "\n";
			num++;
		}	
		
	}
	output += "----------Main Dishes-----------------\n";
	for ( Item* item : items) 
	{
		if (item->ID == "MainCourse")
		{
			output += "(" + to_string(num) + ") " + ((MainCourse*)item)->toString() + "\n";
			num++;
		}
	}
	output += "-----------Beverages-------------------\n";
	for (Item* item : items)
	{
		if (item->ID == "beverage")
		{
			output += "(" + to_string(num) + ") " + ((Beverage*)item)->toString() + "\n";
			num++;
		}
	}
	return output;
}

// returns item pointer of a given index
Item* Menu::find(int index) 
{
	return items[index];
}
