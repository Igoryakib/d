#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


	string stringData;

	int main() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "Enter your initials/������ ���� �������" << endl;
		getline(cin, stringData);
		cout << "Your initials/���� �������: " << stringData << endl;
		reverse(stringData.begin(), stringData.end());
		cout << "Reverse initials/���� ������� � ������: " << stringData;
		return 0;
}

