#include "Money.h"
#include "ListMoney.h"

Money::Money(string nominal, int year, double rate, int id) {
	this->nominalValue = nominal;
	this->releaseYear = year;
	this->exchangeRate = rate;
	this->id = id;
}

void Money::changeData(string nominal, int year, double rate) {
	this->nominalValue = nominal.empty() ? this->nominalValue : nominal;
	this->releaseYear = year ? year : this->releaseYear;
	this->exchangeRate = rate ? rate : this->exchangeRate;
}

int Money::getId()  {
	return this->id;
}

int Money::getYear() {
	return this->releaseYear;
}

string Money::getNominal() {
	return this->nominalValue;
}

void Money::getData() {
	cout << "Nominal value: " << this->nominalValue << "\t" << "release year: " << this->releaseYear << "\t" << "exchange rate: " << this->exchangeRate << endl;
}