#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


	string stringData;

	int main() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "Enter your initials/Ââåä³òü âàø³ ³í³ö³àëè" << endl;
		getline(cin, stringData);
		cout << "Your initials/Âàø³ ³í³ö³àëè: " << stringData << endl;
		reverse(stringData.begin(), stringData.end());
		cout << "Reverse initials/Âàø³ ³í³ö³àëè â ðåâåðñ³: " << stringData;
		return 0;
}

