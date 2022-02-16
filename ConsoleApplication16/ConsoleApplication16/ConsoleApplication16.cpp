#include <iostream>
#include "Header.h"

using namespace std;


int main()
{
	try {
		List* l = nullptr;
		l = new List;
		l->Input();
		l->Display();
		l->Sort();
		l->Display();
		l->Displayc();
		//l->Call();
		l->Resize(2);
		l->Resize(2);
		//l->Display();
		//l->Resize();
		//l->Display();

	}
	catch (const char* s) {
		cerr << s << endl;
	}

	return 0;
}
/*You can use the List class example from this week as a template (however; not required) to help you with this assignment.
Add the following functionality to the list class to do the following:
Add a function to sort the data, calculate the average and determine the median.
Also modify the Resize() function to do the following:  HINT - You'll need to allocate a new array and copy the values from the original array into the new, then deallocate the original array.
Allow the function to resize the modify the size of the array.  If the new size is larger than the old size, the data values in the array should be copied into the new.  If the new array is smaller than the original, it should copy only as many values as the new array will hold.

Use this class to write a program to allow the user to enter a list of values, then display the list, sort and redisplay the list and display the average and median.
Also resize the list to a larger size, display then resize to a smaller size and redisplay to demonstrate the resizing functionality.*/