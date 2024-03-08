#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* stringData = new char[256];
    cout << "Enter your initials/¬вед≥ть ваш≥ ≥н≥ц≥али" << endl;
    cin.getline(stringData, 256);
    cout << "Your initials/¬аш≥ ≥н≥ц≥али: " << stringData << endl;
    char* name = NULL;
    const char* delimitries = " ";
    int counter = 0;
    int counter2 = 0;
    char* next_token = nullptr;
    char* letter[1];
    char* token = strtok_s(stringData, delimitries, &next_token);
    while (token != NULL) {
        if (counter == 1) {
            name = token;
        }
        token = strtok_s(nullptr, delimitries, &next_token);
        counter++;
    }
    cout << name << endl;
    cout << "name:" << name << endl;
    string doubledName = "";
    for (char* i = name; i < name + strlen(name); i++) {
        doubledName += *i;
        doubledName += *i;
    }
    cout << "Doubled name/≤м'€ з подвоЇними л≥терами: " << doubledName << endl;
    delete[] stringData;
    return 0;
}