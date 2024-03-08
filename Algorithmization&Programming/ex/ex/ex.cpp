#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

char** replaceTabWithSpaces(char** text, int numLines, int spacesPerTab);

int main() {
    int numLines = 3;
    char** text = new char* [numLines];
    char text1[] = "\tHello";
    char text2[] = "\tWorld";
    char text3[] = "\t!";
    text[0] = text1;
    text[1] = text2;
    text[2] = text3;

    text = replaceTabWithSpaces(text, numLines, 4);

    for (int i = 0; i < numLines; i++) {
        cout << text[i] << endl;
        delete[] text[i];
    }

    delete[] text;

    return 0;
}

char** replaceTabWithSpaces(char** text, int numLines, int spacesPerTab) {
    for (int i = 0; i < numLines; i++) {
        string line = text[i];
        size_t pos = 0;
        while ((pos = line.find('\t', pos)) != string::npos) {
            line.replace(pos, 1, string(spacesPerTab, ' '));
            pos += spacesPerTab;
        }
        text[i] = new char[line.length() + 1];
        strcpy(text[i], line.c_str());
    }
    return text;
}
