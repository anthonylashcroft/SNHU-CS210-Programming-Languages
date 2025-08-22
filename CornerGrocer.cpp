/*
Name: Anthony Ashcroft
Date: 8/17/2025
*/

#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <conio.h>

#include "CornerGrocer.h"

using namespace std;

// Constructor with filename provided as string. Creates list with defined BuildList function.
Grocer::Grocer(string fileName)
{
	BuildList(fileName);
}

// Returns a reference to the itemList for use in other functions
map<string, int>& Grocer::GetList()
{
	return itemList;
}

// Populates the itemList map with data read from input file and backs up
// data into into Frequency.dat file
void Grocer::BuildList(string fileName) 
{
	ifstream inputFile; // Name of file being read from
	ofstream outputFile; // Name of ifle being backed up
	string itemName;

	inputFile.open(fileName); // Open file
	
	// Verify file is open before continuing
	if (!inputFile) { // File not open. Skip rest of processing.
		cout << "Unable to open file, no data will be presented." << endl;
	}
	else { // File open. Continue processing.
		
		/* Loop to read data from file and populate itemList.
		/ if item exists, it will increase its count
		/ if item does not exists it will add it to the list with a count of 1
		*/
		while (inputFile >> itemName) {
			if (itemList.count(itemName)) {
				itemList[itemName]++;
			}
			else {
				itemList.emplace(itemName, 1);
			}
		}

		inputFile.close(); // Close input file

		// Backup file to Frequency.dat
		cout << "Backing up data file." << endl;

		outputFile.open("Frequency.dat"); // Open or create output file

		// Loop through list to add each item and its count to backup file
		// from previously generated itemList
		for (auto groceries : itemList) {
			outputFile << groceries.first << " " << groceries.second << endl;
		}

		outputFile.close(); // Close output file
	}
}

// Provides a count of all items in the generated list
void Grocer::CountAll(const map<string, int>& itemList)
{	
	system("CLS"); // Clears screen windows only

	// Cycles through each itemList entry and ouputs its name and count
	for (auto groceries : itemList) {
		cout << groceries.first << " " << groceries.second << endl;
	}

	this->AnyKey(); // Wait for user input

	system("CLS"); // Clears screen windows only

}

// Provides a count of all items in generated list as a histogram
void Grocer::CountHistogram(const map<string, int>& itemList)
{
	system("CLS"); // Clears screen windows only

	// Cycles through each itemList entry and outpts its name and a character
	// representation of its count
	for (auto groceries : itemList) {
		cout << groceries.first << " ";
		for (int i = 0; i < groceries.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}

	this->AnyKey(); // Wait for user input

	system("CLS"); // Clears screen windows only
}

// Provides a count of the specific item that the user requested
void Grocer::CountItem(string itemName, const map<string, int>& itemList)
{
	bool itemFound = false;

	system("CLS"); // Clears screen windows only

	// Cycles through list to see if the item the user requested exists
	// and returns its count
	for (auto groceries : itemList) {
		if (groceries.first == itemName) {
			itemFound = true;
			cout << groceries.first << " " << groceries.second << endl;
		}
	}
	// If the item is not found in the list, provide user requested item name
	// and a count of 0
	if (!itemFound) {
		cout << itemName << " 0" << endl;
	}

	this->AnyKey(); // Wait for user input

	system("CLS"); // Clears screen windows only
}

// Waits for user input and then exits function. Used in other function calls
void Grocer::AnyKey() {
	cout << "Press any key to continue." << endl;
	while (true) {
		if (_kbhit()) { // Check if a key is pressed
			char key = _getch();
			break;
		}
	};
}