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
    char* letters[256];
    int counter = 0;
    cout << "Введіть слово: ";
    cin.getline(str, 256);
    for (char* p = str; *p != '\0'; p++) {
        letters[counter] = p;
        counter++;
    }
    for (int i = 0; i < counter; i++) {
        cout << letters[i][0] << endl;
    }
    sort(letters, letters + counter, compare);
    cout << "Відсортовані літери: " << endl;
    for (int i = 0; i < counter; i++) {
        cout << letters[i][0] << endl;
    }
    delete[] str;
    return 0;
}

bool compare(const char* a, const char* b) {
    return *a < *b;
}
