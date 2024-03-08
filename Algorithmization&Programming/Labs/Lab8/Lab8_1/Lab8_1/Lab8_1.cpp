#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <algorithm>

using namespace std;

string readFile(string nameFile);

struct Person {
	char* surname;
	char* initials;
	int grade;
};

bool comparePersons(const Person& a, const Person& b);

bool compareGrades(const Person& a, const Person& b);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person group[10];
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
		Person person;
		char* token2 = strtok_s(token1, delimitries_token2, &next_token2);
		while (token2 != nullptr) {
			if (counter_token2 == 0) {
				person.surname = token2;
			}
			else if (counter_token2 == 1) {
				person.initials = token2;
			}
			else
			{
				person.grade = atoi(token2); //  atoi для перетворення рядка на число
			}
			counter_token2++;
			token2 = strtok_s(nullptr, delimitries_token2, &next_token2);
		}
		group[groupCounter] = person;
		groupCounter++;
		token1 = strtok_s(nullptr, delimitries, &next_token1);
		counter_token2 = 0;
	}

	int totalGrade = 0;
	for (int i = 0; i < groupCounter; i++) {
		totalGrade += group[i].grade;
	}
	double averageGrade = static_cast<double>(totalGrade) / groupCounter;
	cout << "Група посортована за прізвищем" << endl;
	sort(group, group + groupCounter, comparePersons);
	for (int i = 0; i < groupCounter; i++) {
		cout << group[i].surname << '\t';
		cout << group[i].initials << '\t';
		cout << group[i].grade << endl;
	}
	cout << endl;
	cout << "Група посортована за оцінкою" << endl;
	sort(group, group + groupCounter, compareGrades);
	for (int i = 0; i < groupCounter; i++) {
		cout << group[i].surname << '\t';
		cout << group[i].initials << '\t';
		cout << group[i].grade << endl;
	}

	cout << "Середній бал групи: " << averageGrade << endl;

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

bool comparePersons(const Person& a, const Person& b) {
	int surnameComparison = strcmp(a.surname, b.surname);
	return surnameComparison < 0;
}

bool compareGrades(const Person& a, const Person& b) {
	return a.grade > b.grade;
}