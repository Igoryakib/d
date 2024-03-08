#pragma once
#include <string>
#include <iostream>

using namespace std;

class Money {
private:
	string nominalValue;
	int releaseYear;
	double exchangeRate;
	int id;

public:

	Money(string nominal, int year, double rate, int id);

	void changeData(string nominal, int year, double rate);

	int getId();

	int getYear();

	string getNominal();

	void getData();

};