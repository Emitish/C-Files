//Fig. 10.9: Date.c
// Date class member-function definitions
#include <iostream>
#include <stdexcept>
#include "Date_Implementation.h"
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date_Implementation::Date_Implementation(int mn, int dy, int yr)
{
	if (mn > 0 && mn <= monthPerYear) // validate the month
		month = mn;
	else
		throw invalid_argument("month must be 1-12");

	year = yr; // validate the year
	day = checkDay(dy); // validate the day

	// output Date object to show when its constructor is called
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

// print Date object in form month/day/year
void Date_Implementation::print() const
{
	cout << month << "/" << day << "/" << year;
}

// output Date object to show when its destructor is called
Date_Implementation::~Date_Implementation()
{
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

// utility function to confirm proper day value baed on 
// month and year; handles leap years, too
int Date_Implementation::checkDay(int testDay) const
{
	static const int daysPerMonth[monthPerYear+1] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return testDay;

	throw invalid_argument("Invalid day for current month and year");
}
