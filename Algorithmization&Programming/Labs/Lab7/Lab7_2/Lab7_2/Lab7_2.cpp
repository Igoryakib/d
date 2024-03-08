#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

char* getDataString();

void createFile();

void writeFile(string nameFile, char data[256]);

char* readFile(string nameFile);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* data = getDataString();
	cout << "Ви ввели такі слова: " << data << endl;
	createFile();
	writeFile("doc.txt", data);
	char* dataFromFile = readFile("doc.txt");
	cout << "Ваші слова записані у файл: " << dataFromFile << endl;

	cout << "Введіть слово для заміни" << endl;
	char* newData = getDataString();
	delete[] dataFromFile;
	dataFromFile = newData;
	writeFile("doc.txt", dataFromFile);
	char* newDataFromFile = readFile("doc.txt");
	cout << "Ваші слова записані у файл: " << newDataFromFile << endl;
	delete[] data;
	return 0;
}

char* getDataString() {
	char* dataString = new char[256];
	cout << "Введіть слова:" << endl;
	cin.getline(dataString, 256);
	return dataString;
}

void createFile() {
	ofstream file("doc.txt", ios_base::out);
}

void writeFile(string nameFile, char data[256]) {
	ofstream file(nameFile);
	if (file.is_open()) {
		file << data;
		file.close();
	}
}

char* readFile(string nameFile) {
	ifstream file(nameFile);
	char* data = new char[256];
	if (file.is_open()) {
		file.getline(data, 256);
		file.close();
	}
	return data;
}