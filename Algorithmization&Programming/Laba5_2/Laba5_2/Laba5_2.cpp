#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string S1, S2;

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
	cout << "��� ����� S2: " << S2 << endl;
	string common_chars = "";
	for (int i1 = 0; i1 < S1.length(); i1++) {
		for (int i2 = 0; i2 < S2.length(); i2++) {
			if (S1[i1] == S2[i2] && common_chars.find(S1[i1]) == string::npos) {
				common_chars += S1[i1];
			}
		}
	}
	S1 = common_chars + S1;
	cout << "��� ����� S1 � �������� ���������� � S2: " << S1 << endl;
	return 0;
}