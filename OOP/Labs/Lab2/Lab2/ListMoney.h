#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Money.h"

class ListMoney {
private:
	vector<Money> listMoneys;
	int listLength = listMoneys.size();
	int maxListLength = 10;

public:
	ListMoney();

	void changeMaxLength(int limit);

		void addNewObj(Money obj);

		void findElement(int id);

		void findChangeElement(int id, string nominal, int year, double rate);

		void getAllList();

		void deleteMoney(int id);

		void get2018Elements(int year);

		void sortCurrencyByNominal();
};
