//Fig. 9.10: main_Time.c
#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

int main()
{
	Time t1; // all arguments defaulted
	Time t2(2); // hour specified; minute and second defaulted
	Time t3(21,34); // hour and minute specified; second defaulted
	Time t4(12,25,42); // hour, minute and second specified

	cout << "Constructed with:\n\nt1: all arguments defualted\n  ";
	t1.printUniversal();
	cout << "\n  ";
	t1.printStandard();

	cout << "\n\nt2: hour specified\n  ";
	t2.printUniversal();
	cout << "\n  ";
	t2.printStandard();

	cout << "\n\nt3: hour and minute specified\n  ";
	t3.printUniversal();
	cout << "\n  ";
	t3.printStandard();

	cout << "\n\nt4: hour, minute and second specified\n  ";
	t4.printUniversal();
	cout << "\n  ";
	t4.printStandard();
	
	// attempt to initialize t5 with invalid values
	try
	{
		Time t5(27, 74, 99);
	}

	catch (invalid_argument &e)
	{
		cout << "\n\nException while initializing t5: " << e.what() << endl;
	}
}
