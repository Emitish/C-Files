//Fig. 10.8: Date_Implementation.h
// Date class definition; Member functions defined in Date.c

#ifndef DATE_IMPLEMENTATION_H
#define DATE_IMPLEMENTATION_H

class Date_Implementation
{
public:
	static const int monthPerYear = 12; // number of months in a year
	Date_Implementation(int = 1, int = 1, int = 1900); // default constructor
	void print() const; // print date in month/day/year format
	~Date_Implementation(); // provided to confirm destruction order

private:
	int month;
	int day;
	int year;

	int checkDay(int) const;
};

#endif
