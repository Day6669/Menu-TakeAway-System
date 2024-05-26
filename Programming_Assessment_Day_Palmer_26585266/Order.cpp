#include "Order.h"

Order::Order()
{
	savings = 0.0;
	total = 0;
}

// adds item to the order
void Order::add(Item* index) 
{
	items.push_back(index);
}

// removes item from the order
void Order::remove(int numbers) 
{
	if (items.empty())
	{
		cout << "No Items in Order!!" << endl;
	}
	else if (numbers > items.size() || numbers < 0) 
	{
		cout << "Your order is not that long!";
	} 
	else
	{
		items.erase(items.begin() + numbers);
	}

}

/// <summary>
///		function to handle get the item from the array
///		for error handling we return a null pointer 
///		in case there was no item this means we can 
///		delegate the error to the caller
/// </summary>
/// <param name="idx">
///		Index of the item to get
/// </param>
/// <returns>
///		either a pointer to an item or a null pointer 
///		if the item is not found
/// </returns>
Item* Order::getname(int idx) 
{
	if(items.size() == 0 && (idx >= items.size() || idx < 0)) 
	{
		cout << "Invalid item" << endl;
		return nullptr;
	}
	else 
	{
		return items[idx];
	}
	
}
// calls to string of each item in the order and formats them for an appropriate receipt checkout
string Order::toString()
{
	float price = calculateTotal();
	string output = " ";
	output += "====Checkout====\n";
	int num = 1;
	for (Item* item : items)
	{
		if (item->ID == "appetiser")
		{
			output += "(" + to_string(num) + ")" + ((Appetiser*)item)->toString() + "\n";
		}
		else if (item->ID == "beverage")
		{
			output += "(" + to_string(num) + ")" + ((Beverage*)item)->toString() + "\n";
		}
		else
		{
			output += "(" + to_string(num) + ")" + item->toString() + "\n";
		}
		num++;
	}
	output += "------------\n";

	if (savings > 0) output += "2-4-1 discount applied! Savings: $" + RoundString(savings) + "\n";
	output += "Total: $" + RoundString(price);

	return output;
}
// adds the prices of each item together for a total cost of the order
float Order::calculateTotal() 
{
	float total = 0;

	vector <float> prices;
	for (int i = 0; i < items.size(); i++)
	{
		total += items[i]->price;
		if (items[i]->ID == "appetiser" && ((Appetiser*)(items[i]))->isTwoForOne()) // applies 2-4-1 offer for appetisers
		{
			prices.push_back(items[i]->price);
		}

		if (prices.size() == 2) // applies the savings of the above statement
		{
			total -= prices[0];
			savings += prices[0];
			prices.clear();
		}
	}
	return total;
}

void Order::printReceipt()
{
	// create and open a text file
	ofstream MyFile("Receipt.txt");
	// write to file 
	MyFile << toString();
	// close the file
	MyFile.close();
}
	