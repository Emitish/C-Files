//Fig. 10.8: Date.h
// Date class definition; Member functions defined in Date.c
#ifndef DATE_H
#define DATE_H

class Date_Implementation;

class Date
{
public:
	static const int monthPerYear = 12; // number of months in a year
	Date(int = 1, int = 1, int = 1900); // default constructor
	void print() const; // print date in month/day/year format
	~Date(); // provided to confirm destruction order

private:
	Date_Implementation *ptr;
};

#endif
