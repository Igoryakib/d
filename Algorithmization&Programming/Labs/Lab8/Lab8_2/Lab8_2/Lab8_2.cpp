#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Clothing {
    string type;
    string name;
    string size;
    double price;
};

vector<Clothing> clothes;

void addClothing(Clothing c) {
    clothes.push_back(c);
}

void searchClothing(string name) {
    for (const auto& c : clothes) {
        if (c.name == name) {
            cout << "Found: " << c.name << ", " << c.type << ", " << c.size << ", " << c.price << endl;
        }
    }
}

void viewClothes() {
    for (const auto& c : clothes) {
        cout << c.name << ", " << c.type << ", " << c.size << ", " << c.price << endl;
    }
}

void modifyClothing(string name, string newType, string newSize, double newPrice) {
    for (auto& c : clothes) {
        if (c.name == name) {
            c.type = newType;
            c.size = newSize;
            c.price = newPrice;
        }
    }
}

void deleteClothing(string name) {
    clothes.erase(remove_if(clothes.begin(), clothes.end(), [name](const Clothing& c) { return c.name == name; }), clothes.end());
}

bool compareByName(const Clothing& a, const Clothing& b) {
    return a.name < b.name;
}

void sortClothes() {
    sort(clothes.begin(), clothes.end(), compareByName);
}

void saveToFile() {
    ofstream file("clothes.txt");
    if (file.is_open()) {
        for (const auto& c : clothes) {
            file << c.name << ", " << c.type << ", " << c.size << ", " << c.price << endl;
        }
    }
    file.close();
}

int main() {
    // Adding new items
    cout << "Adding new items" << endl;
    addClothing({ "T-Shirt", "Nike", "M", 29.99 });
    addClothing({ "Jeans", "Levis", "32", 49.99 });
    addClothing({ "Jacket", "Adidas", "L", 79.99 });
    saveToFile();
    viewClothes();
    cout << "Searching for an item by name" << endl;
    // Searching for an item by name
    searchClothing("Nike");
    cout << endl;
    // Viewing all items
    cout << "Viewing all items" << endl;
    viewClothes();
    cout << endl;
    // Modifying item details
    cout << "Modifying item details" << endl;
    modifyClothing("Nike", "T-Shirt", "S", 29.99);
    saveToFile();
    viewClothes();
    // Deleting an item
    cout << endl << "Deleting an item" << endl;
    deleteClothing("Adidas");
    saveToFile();
    viewClothes();
    // Sorting items by name
    cout << endl << "Sorting items by name" << endl;
    sortClothes();

    // Saving results to a file
    saveToFile();

    return 0;
}
