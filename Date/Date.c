//Fig. 10.9: Date.c
// Date class member-function definitions
#include <iostream>
#include <stdexcept>
#include "Date.h"
#include "Date_Implementation.h"
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int mm, int dy, int yr)
{
	ptr = new Date_Implementation(mm,dy,yr);
}

// print Date object in form month/day/year
void Date::print() const
{
	ptr->print();
}

// output Date object to show when its destructor is called
Date::~Date()
{
	delete ptr;
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

// utility function to confirm proper day value baed on 
// month and year; handles leap years, too

