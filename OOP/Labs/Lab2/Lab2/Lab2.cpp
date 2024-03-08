#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Money.h"
#include "ListMoney.h"

using namespace std;

int main() {

	Money dollar("dollar", 1792, 38.1, 1);
	Money euro("euro", 1999, 39.6, 2);
	Money pound("pound", 1124, 43.2, 3);
	Money CZK("koruna česká", 1993, 1.620, 4);
	Money AUD("Australian dollar", 1966, 25.28, 5);
	Money hryvna("euro", 1996, 1, 6);
	ListMoney money;
	money.addNewObj(dollar);
	money.addNewObj(euro);
	money.addNewObj(pound);
	money.addNewObj(CZK);
	money.addNewObj(AUD);
	money.addNewObj(hryvna);
	money.getAllList();
	money.findChangeElement(1, "dollar2", 12, 12);
	money.getAllList();
	return 0;
}