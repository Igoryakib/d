#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* str = new char[256];
    cout << "������ �����: ";
    cin.getline(str, 256);

    int count = 0;
    for (char* p = str; p < str + strlen(str) / 2; p++) {
        if (*p == 'S' || *p == 's') {
            count++;
        }
    }

    cout << "�����: " << str << std::endl;
    cout << "ʳ������ 'S' � ������ ������� �����: " << count << std::endl;

    delete[] str;
    return 0;
}
