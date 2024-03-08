#include <iostream>
#include <windows.h>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(const char* a, const char* b);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* str = new char[256];
    char* upperWords[256];
    int counter = 0;
    cout << "Введіть рядок: ";
    cin.getline(str, 256);
    const char* delimitries = " ,.!?;:";
    char* next_token = nullptr;
    char* token = strtok_s(str, delimitries, &next_token);
    while (token != nullptr) {
        if (isupper(*token)) {
            upperWords[counter] = token;
            counter++;
        }
        token = strtok_s(nullptr, delimitries, &next_token);
    }
    for (int i = 0; i < counter; i++) {
        cout << upperWords[i] << endl;
    }
    sort(upperWords, upperWords + counter, compare);
    cout << "Відсортовані слова: " << endl;
    for (int i = 0; i < counter; i++) {
        cout << upperWords[i] << endl;
    }
    delete[] str;
    return 0;
}

bool compare(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}