#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cout << "Enter your string: ";

    const int MAX_SIZE = 100;
    char* input = new char[MAX_SIZE];
    cin.getline(input, MAX_SIZE);

    char* context = nullptr;
    const char* delimitries = " ";
    char* next_token = nullptr;
    char* token = strtok_s(input, delimitries, &next_token);
    int count = 0;

    while (token != nullptr) {
        if (*token == 'a' || *token == 'A') {
            count++;
        }
        token = strtok_s(nullptr, delimitries, &next_token);
    }

    cout << "The number of words starting with the letter 'a': " << count << endl;

    delete[] input;

    return 0;
}
