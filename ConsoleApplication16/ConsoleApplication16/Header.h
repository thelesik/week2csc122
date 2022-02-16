#pragma once
#include <exception>
#include <iostream>
#include <algorithm>
#include "Header2.h"
#include "Header1.h"
using namespace std;
void List::Clear()
{
	if (size > 0) {
		delete[] data;
		size = 0;
		data = nullptr;
	}
}

void List::Resize(long numValues) // modified
{
	if (data == nullptr) {
		try {
			if (numValues < 1 || numValues > MAX_SIZE) {
				throw "Error! Invalid list size specified.";
			}
			Clear();
			data = new double[numValues];
			if (data == nullptr) {
				throw "Error! Could not allocate memory for list.";
			}
			size = numValues;
		}
		catch (std::exception& e) {
			throw "Error! Could not allocate memory for list.";
		}

	}

	else {
		int newv = 0;
		cout << "Please anter the size of new array ";
		cin >> newv;
		double* arr = new double[newv];
		for (int i = 0; i < newv; ++i) {
			if (i >= 0 || i < size)
			{
				arr[i] = data[i];
			}
			if (i >= size) 
				{ arr[i] = 0; }
		}
		try {
			if (newv < 1 || newv > MAX_SIZE) {
				throw "Error! Invalid list size specified.";
			}
			Clear();
			data = new double[newv];
			if (data == nullptr) {
				throw "Error! Could not allocate memory for list.";
			}
			size = newv;
		}
		catch (std::exception& e) {
			throw "Error! Could not allocate memory for list.";
		}

		for (int i = 0; i < size; ++i) {
			data[i] = arr[i];
		}
		Display();

	}

	//CallNew(data, size);
}

/*
void List::CallNew(double* data, long pos) { // old 
	int newv = 0;
	cout << "Please anter the size of new array ";
	cin >> newv;
	double* arr = new double[newv];

	for (int i = 0; i < newv; ++i) {
		if (i >= 0 || i < pos) { arr[i] = data[i]; }
		if (i >= pos) { arr[i] = 0; }

	}

	//Clear();
	if (pos =! newv){ Resize(newv); }
	else { }
	if (pos == newv) {
		cout << "dsdsdsdfsdfsdfgsdg" << endl;
	}
	
	
	for (int i = 0; i < newv; ++i) {
		SetValue(arr[i], i);
	}
	for (int i = 0; i < newv; ++i) {
		cout << data[i] << endl;
	}
	Display();
}
void List::Call() { // call of CallNew()
	//CallNew(data, size);
}*/
void List::SetValue(double value, long pos)
{
	if (pos < 0 || pos >= size) {
		throw "Error! Invalid position in list specified.";
	}
	data[pos] = value;
}

double List::GetValue(long pos)
{
	if (pos < 0 || pos >= size) {
		throw "Error! Invalid position in list specified.";
	}
	return data[pos];
}
void List::Sort() {
	cout << "Sorted data : " << endl;
	sort(data, data + size);

}
void List::Average(double* data, int size) //average and median
{
	double sum = 0,
		average;
	for (int count = 0; count < size; count++)
	{
		sum = (sum + data[count]);
	}
	average = (sum / size);
	if (size % 2 == 0) { // kratne/even 
		int i = 0;
		i = (size - 1) / 2;
		cout << "Median is = " << (data[i] + data[i + 1]) / 2 << endl;
	}
	else {
		int i = 0;
		i = (size - 1) / 2;
		cout << "Median is = " << data[i] << endl;
	}
	cout << "Average is = " << average << endl;
}
void List::Displayc() {  //display for average
	Average(data, size);
}
void List::Input()
{
	try {
		if (size == 0) {
			long x = ReadValue<long>("Number of values? ");
			Resize(x);
		}

		for (double* ptr = data; ptr < data + size; ptr++) {
			*ptr = ReadValue<double>("Value? ");
		}
	}
	catch (const char* s) {
		throw s;
	}


}

void List::Display()
{
	if (size > 0) {
		std::cout << "Array: " << endl;
		for (double* ptr = data; ptr < data + size; ptr++) {
			std::cout << *ptr << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "List is emptry." << endl;
	}

}


List::List()
{
	data = nullptr;
	size = 0;
}

List::~List()
{
	Clear();
}

/*You can use the List class example from this week as a template (however; not required)
to help you with this assignment.
Add the following functionality to the list class to do the following:

Add a function to sort the data, calculate the average and determine the median.

Also modify the Resize() function to do the following:  HINT -
You'll need to allocate a new array and copy the values from the original
array into the new, then deallocate the original array.
Allow the function to resize the modify the size of the array.
If the new size is larger than the old size, the data values in the
array should be copied into the new.  If the new array is smaller than
the original, it should copy only as many values as the new array will hold.

Use this class to write a program to allow the user to enter a list of values,
then display the list, sort and redisplay the list and display the average and median.
Also resize the list to a larger size, display then resize to a smaller size and
redisplay to demonstrate the resizing functionality.*/