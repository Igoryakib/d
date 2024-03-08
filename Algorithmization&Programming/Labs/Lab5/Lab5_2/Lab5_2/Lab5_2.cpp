#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string S1, S2;
	vector<int> longestArrNums;
	vector<char> longestArrLetters;
	vector<int> currentNum;
	vector<char> currentLet;
	cout << "Введіть текст/символи для S1: " << endl;
	getline(cin, S1);
	cout << "Введіть текст/символи для S2: " << endl;
	getline(cin, S2);
	while (S1.length() > 100 || S2.length() > 100) {
		cout << "Ви ввели більше 100 символів для S1 або S2. Спробуйте ще раз: " << endl;
		cout << "Введіть текст/символи для S1: " << endl;
		getline(cin, S1);
		cout << "Введіть текст/символи для S2: " << endl;
		getline(cin, S2);
	}
	cout << "Ваш рядок S1: " << S1 << endl;
	for (int i = 0; i <= S1.length(); i++) {
		if (S1[i] >= '0' && S1[i] <= '9') {
			currentNum.push_back(S1[i] - '0');
			if (currentNum.size() > longestArrNums.size()) {
				longestArrNums = currentNum;
			}
		}
		else {
			currentNum.clear();
		}
	}
	cout << "Найдовша послідовність цифр у S1: ";
	for (int i = 0; i < longestArrNums.size(); i++) {
		cout << longestArrNums[i];
	}
	cout << endl << "Ваш рядок S2: " << S2 << endl;
	for (int i = 0; i <= S2.length(); i++) {
		if (S2[i] == 'а' || S2[i] == 'е' || S2[i] == 'є' || S2[i] == 'и' || S2[i] == 'і'
			|| S2[i] == 'ї' || S2[i] == 'о' || S2[i] == 'у' || S2[i] == 'ю' || S2[i] == 'я') {
			currentLet.push_back(S2[i]);
			if (currentLet.size() > longestArrLetters.size()) {
				longestArrLetters = currentLet;
			}
		}
		else {
			currentLet.clear();
		}
	}
	cout << "Найдовша послідовність голосних у S2: ";
	for (int i = 0; i < longestArrLetters.size(); i++) {
		cout << longestArrLetters[i];
	}
	return 0;