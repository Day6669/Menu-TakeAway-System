/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand, command;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	// use the input cout so the user can understand they are able to input and where to input
	// this while loop grabs the command the user types in to check the the length using a pointer
	// and makes it so the commands are no longer case sensitive
	while (userCommand != "exit")
	{
		cout << "Input: ";
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());
		int charPos = 0;
		for (char* c = cstr; *c != '\0'; ++c, charPos++)
		{
			char newChar = (char)tolower(*c);
			cstr[charPos] = newChar;
		}

		char* token;
		token = strtok(cstr, " ");
		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		

		if (parameters.empty()) // error handling for empty user input
		{
			continue;
		}

		// use of an if statement so if the parameters are entered empty 
		// then it goes back to the menu rather than crashing 
		// (used as a form of error handling)
		command = parameters[0];

		// allows the user to know that if it is not within the if statements specifications in the brackets
		// the program will not accept it with the cout comment, clears the parameter in order to let
		// the user enter the command again and continue from the top
		if (parameters.size() > 1 && (stoi(parameters[1]) <= 0 || stoi(parameters[1]) > menu.items.size()))
		{
			cout << "out of bounds" << endl;
			parameters.clear();
			continue;
		}

		// if they call the command menu it will print the menu for the user to read
		// otherwise if they use the add or remove commands it will add or remove the items from the checkout
		if (command.compare("menu") == 0) 
		{
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			// an if is used to check the parameters size so that the parameters are able to be added one at a time
			if (parameters.size() == 2) 
			{
				Item* choice; // you need to instantiate this using the menu object!
				choice = menu.find(stoi(parameters[1]) - 1); // finds given item in menu and adds it to the order
				cout << choice->name << " added to order!" << endl;
				order.add(choice);
			}
			else if (parameters.size() > 2 ) // the if enables more than one item to be added at once using a for loop
			{
				for (int i = 1; i < parameters.size(); i++)
				{
					Item* choice; 
					choice = menu.find(stoi(parameters[i]) - 1);
					cout << choice->name << " added to order!" << endl;
					order.add(choice);
				}
			}
			else 
			{
				cout << "not enough parameters!!" << endl;
			}
		}
		else if (command.compare("remove") == 0)
		{
			if (parameters.size() == 2)// an if is used to check the parameters size so that the parameters are able to be added one at a time
			{
				Item* choice = order.getname((stoi(parameters[1]) - 1));
				if (choice != nullptr)
				{
					cout << choice->name << " removed from order." << endl;
					order.remove(stoi(parameters[1]) - 1);
				}
			}
			else if (parameters.size() > 2) // the if enables more than one item to be removed at once using a for loop
			{
				for (int i = 1; i < parameters.size(); i++)
				{
					Item* choice = order.getname((stoi(parameters[i]) - 1));
					cout << choice->name << " removed from order." << endl;
					order.remove(stoi(parameters[i]) - 1);
				}
			}
			else
			{
				cout << "not enough parameters!!" << endl;
			}
		}
	
		else if (command.compare("checkout") == 0)
		{
			cout << order.toString() << endl;
			string input;
			cout << "Do you want to place your order?" << " Type 'y' to confirm or 'n' to go back and modify it: ";
			// NOTE: using cin messes with the stdin buffer so need to use the same function to clear it
			getline(cin, input);
			// uses an if statement to allow the user to choose to checkout or modify their order
			if (input == "y")
			{
				order.printReceipt(); // print receipt writes to the file
				break;
			}
			else if (input == "n")
			{
				cout << "Enter menu again to continue." << endl;
			}
			else
			{
				cout << "Incorrect letter" << endl;
				input.clear();
				continue;
			}
		}
		
		else if (command.compare("help") == 0) // creates a help menu with all the usable commands listed
		{
			cout << "help" << " - " << "Opens the help page for commands." << endl;
			cout << "menu" << " - " << "Displays the menu." << endl;
			cout << "add number" << " - " << "Adds the item from the menu corresponding to the number inputted." << endl;
			cout << "remove number" << " - " << "Removes the item from the checkout corresponding to the number inputted." << endl;
			cout << "checkout" << " - " << "Allows you to enter the checkout menu to complete purchase." << endl;
			cout << "exit" << " - " << "Exits the program." << endl;
		}

		parameters.clear();
	}
	// formats exiting the program in a nice manner
	cout << "Press any key to quit...";
	std::getchar();

}