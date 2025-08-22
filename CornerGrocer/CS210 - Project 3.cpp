/*
Name: Anthony Ashcroft
Date: 8/17/2025
*/

#include <string>

#include "CornerGrocer.h"

using namespace std;

// Declare function to display menu
void displayMenu();

// Declare function to accept user menu choice
int getSelection();

// Declare function to call Class functions
void processSelection(int, Grocer&);

const int EXITVALUE = 4; // Static value used to exit the program

int main()
{	
	// Declare variables
	string fileName = "CS210_Project_Three_Input_File.txt";
	int menuChoice = 0;
	map<string, int> itemList;

	// Custom grocer class for processing menu choices
	Grocer groceryList(fileName);

	// Loop to provide menu to user until they wish to exit
	do {
		displayMenu();
		menuChoice = getSelection();
		processSelection(menuChoice, groceryList);
	} while (menuChoice != EXITVALUE);

	return 0;
}

// Display menu options
void displayMenu()
{
	cout << " --------------------------------------------" << endl;
	cout << "|               Corner Grocer                |" << endl;
	cout << " --------------------------------------------" << endl;
	cout << "Please make a selection from the list below." << endl << endl;
	cout << "1. Look for item." << endl;
	cout << "2. Count all items." << endl;
	cout << "3. Display counts as histogram." << endl;
	cout << EXITVALUE << ". Exit program." << endl;
}

// Obtain user input for menu selection
int getSelection()
{
	int selection = 0;
	bool invalidSelection = true;

	// Retrive user input and check for valid selections
	do {
		cin >> selection;
		invalidSelection = ((selection < 1 || selection > EXITVALUE));
		if (invalidSelection) {
			cout << "You have selected an option that is not valid. Please select options 1 - " << EXITVALUE << "." << endl;
		}
		
		// Clears input buffer if invalid input has been provided
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (invalidSelection);

	return selection;
}

// Call appropriate Grocer class function based on user choice
void processSelection(int menuChoice, Grocer& groceryList)
{
	string searchString;

	switch (menuChoice) {
	case 1:
		cout << "Please type the name of the item you wish to have counted." << endl;
		// Clear any data stored in buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, searchString);
		groceryList.CountItem(searchString, groceryList.GetList()); // Call function that counts how many of requested item
		break;
	case 2:
		groceryList.CountAll(groceryList.GetList()); // Call function that provides a count of all items
		break;
	case 3:
		groceryList.CountHistogram(groceryList.GetList()); // Call function that provides a histogram of all items
		break;
	case 4:
		break;
	default:
		break;
	}
}
