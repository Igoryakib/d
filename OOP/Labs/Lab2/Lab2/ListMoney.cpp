#include "ListMoney.h"
#include "Money.h"
#include <algorithm>

ListMoney::ListMoney() {
}

void ListMoney::changeMaxLength(int limit) {
	this->maxListLength = limit;
}

void ListMoney::addNewObj(Money obj) {
	if (this->listLength < this->maxListLength) {
		this->listMoneys.push_back(obj);
	}
	else {
		cout << "overfilled";
	}
}

void ListMoney::findElement(int id) {
	for (Money& m : this->listMoneys) {
		if (m.getId() == id) {
			m.getData();
		}
	}
}

void ListMoney::findChangeElement(int id, string nominal, int year, double rate) {
	for (Money& m : this->listMoneys) {
		if (m.getId() == id) {
			m.changeData(nominal, year, rate);
			m.getData();
		}
	}
}

void ListMoney::getAllList() {
	for (Money& m : this->listMoneys) {
		m.getData();
	}
}

void ListMoney::deleteMoney(int id) {
	this->listMoneys.erase(remove_if(this->listMoneys.begin(), this->listMoneys.end(), [id](Money m) { return m.getId() == id; }), this->listMoneys.end());
}

void ListMoney::get2018Elements(int year) {
	for (Money& m : this->listMoneys) {
		if (m.getYear() == year) {
			m.getData();
		}
	}
}

void ListMoney::sortCurrencyByNominal() {
	sort(this->listMoneys.begin(), this->listMoneys.end(),
		[](Money a, Money b) { return a.getNominal() < b.getNominal(); });
	this->getAllList();
}