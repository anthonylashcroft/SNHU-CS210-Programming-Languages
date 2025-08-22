/*
Name: Anthony Ashcroft
Date: 8/17/2025
*/

#ifndef CORNERGROCER_H
#define CORNERGROCER_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class Grocer {
public:
	// Declare functions
	Grocer() {}; // Default constructor
	Grocer(std::string); // Constructor with filename provided
	
	// Mutators
	void BuildList(std::string); // Builds the list of items with filename as string

	// Accessors
	std::map<std::string, int>& GetList(); // Returns the current list of items
	void CountAll(const std::map<std::string, int>&); // Displays list of all items with counts
	void CountHistogram(const std::map<std::string, int>&); // Displays list of all items as histogram
	void CountItem(std::string, const std::map<std::string, int>&); // Displays the count of requested item

private:
	std::map<std::string, int> itemList; // Generated list of items

	// Assist functions
	void AnyKey(); // Pauses screen until user presses key
};

#endif // CORNERGROCER_H
