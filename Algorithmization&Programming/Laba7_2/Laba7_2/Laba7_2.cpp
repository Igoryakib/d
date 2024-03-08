#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int findShortestWordLength(const std::string& line) {
    std::istringstream iss(line);
    std::string word;
    int shortestLength = 100;

    while (iss >> word) {
        int currentLength = word.length();
        if (currentLength < shortestLength) {
            shortestLength = currentLength;
        }
    }

    return shortestLength;
}
void printShortestWord(const std::string& line) {
    std::istringstream iss(line);
    std::string word;
    int shortestLength = findShortestWordLength(line);
    bool foundShortestWord = false;

    while (iss >> word) {
        if (word.length() == shortestLength) {
            std::cout << "For the line: " << line << std::endl;
            std::cout << "Shortest word is: " << word << std::endl << "Length of the shortest word: " << shortestLength << std::endl;
            foundShortestWord = true;
        }
    }

    if (!foundShortestWord) {
        std::cout << "No words found in the line." << std::endl;
    }

    std::cout << std::endl;
}

void analyzeFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        printShortestWord(line);
    }

    file.close();
}

int main() {
    std::string filename;

    std::cout << "Enter the filename to analyze: ";
    std::cin >> filename;

    analyzeFile(filename);
    return 0;
}
