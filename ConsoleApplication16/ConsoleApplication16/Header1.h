#pragma once
#ifndef LIST_H
#define LIST_H

class List
{
private:
	double* data;
	long size;

public:
	enum { MAX_SIZE = 1000 };

	void Resize(long numValues);
	void Clear();
	void SetValue(double value, long pos);
	double GetValue(long pos);
	void Input();
	void Sort();
	void Display();
	void Displayc();
	//void CallNew(double* testScores, long pos);
	//void Call();
	void Average(double* testScores, int numScores);
	List();
	~List();
};

#endif