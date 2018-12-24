/* 
 * Station.cpp
 *
 * This file writes a parameterized constructor for the
 * station class and checks for a match between the station
 * object's information and the inputted parameter.
 * The file also contains a function that prints
 * station information - both name and access.
 */

#include "Station.h"
#include <iostream>
using namespace std;

// Constructor
Station::Station()
{
	name = "NoName";
    access = false;
}

// Parameterized Constructor
Station::Station(string input_name, bool input_access)
{
    name = input_name;
    access = input_access;
}

// Function: is_equal
// Input: Station object
// Returns: bool of access
// Does: Checks if the station's object contains
// 		 the same info as given by the parameter,
//	     returns true if it is and false if not.
bool Station::is_equal(Station s)
{
    if (s.name == name && s.access == access)
    	return true;
    else
    	return false;
}

// Function: print
// Input: ostream pointer
// Returns: none
// Does: Prints a string of the station name
//		 and whether or not the station is 
//		 accessible, as indicated by A and U.
void Station::print(ostream &outfile)
{
    cout << endl;
    cout << name << ": ";
    if (access == true)
    	cout << "A";
    else
    	cout << "U";
}


