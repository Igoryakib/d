#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <algorithm>

using namespace std;

string readFile(string nameFile);

struct Weather {
	char* date;
	int temperature;
	char* rainfall;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Weather group[10];
	string data = readFile("doc.txt");
	int counter_token2 = 0;
	int groupCounter = 0;
	char* profileData[256];
	const char* delimitries = "\n";
	const char* delimitries_token2 = " ";
	char* next_token1 = nullptr;
	char* next_token2 = nullptr;
	char* token1 = strtok_s(&data[0], delimitries, &next_token1);
	while (token1 != nullptr) {
		Weather day;
		char* token2 = strtok_s(token1, delimitries_token2, &next_token2);
		while (token2 != nullptr) {
			if (counter_token2 == 0) {
				day.date = token2;
			}
			else if (counter_token2 == 1) {
				day.temperature = atoi(token2);
			}
			else
			{
				day.rainfall = token2; //  atoi для перетворення рядка на число
			}
			counter_token2++;
			token2 = strtok_s(nullptr, delimitries_token2, &next_token2);
		}
		group[groupCounter] = day;
		groupCounter++;
		token1 = strtok_s(nullptr, delimitries, &next_token1);
		counter_token2 = 0;
	}


	int thehighestTemperature = 0;
	int weatherIndex = 0;
	cout << "Список днів: " << endl;
	for (int i = 0; i < groupCounter; i++) {
		cout << "День: " << '\t' << group[i].date << '\t' << group[i].temperature << '\t' << group[i].rainfall << endl;
		if (thehighestTemperature < group[i].temperature) {
			thehighestTemperature = group[i].temperature;
			weatherIndex = i;
		}
	}
	cout << endl;
	cout << "Найтепліший день: " << group[weatherIndex].date << '\t' << group[weatherIndex].temperature << '\t' << group[weatherIndex].rainfall;
	return 0;
}

string readFile(string nameFile) {
	ifstream file(nameFile);
	string data;
	if (file.is_open()) {
		getline(file, data, '\0');
		file.close();
	}
	return data;
}