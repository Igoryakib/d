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
	cout << "������ �����/������� ��� S1: " << endl;
	getline(cin, S1);
	cout << "������ �����/������� ��� S2: " << endl;
	getline(cin, S2);
	while (S1.length() > 100 || S2.length() > 100) {
		cout << "�� ����� ����� 100 ������� ��� S1 ��� S2. ��������� �� ���: " << endl;
		cout << "������ �����/������� ��� S1: " << endl;
		getline(cin, S1);
		cout << "������ �����/������� ��� S2: " << endl;
		getline(cin, S2);
	}
	cout << "��� ����� S1: " << S1 << endl;
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
	cout << "�������� ����������� ���� � S1: ";
	for (int i = 0; i < longestArrNums.size(); i++) {
		cout << longestArrNums[i];
	}
	cout << endl << "��� ����� S2: " << S2 << endl;
	for (int i = 0; i <= S2.length(); i++) {
		if (S2[i] == '�' || S2[i] == '�' || S2[i] == '�' || S2[i] == '�' || S2[i] == '�'
			|| S2[i] == '�' || S2[i] == '�' || S2[i] == '�' || S2[i] == '�' || S2[i] == '�') {
			currentLet.push_back(S2[i]);
			if (currentLet.size() > longestArrLetters.size()) {
				longestArrLetters = currentLet;
			}
		}
		else {
			currentLet.clear();
		}
	}
	cout << "�������� ����������� �������� � S2: ";
	for (int i = 0; i < longestArrLetters.size(); i++) {
		cout << longestArrLetters[i];
	}
	return 0;