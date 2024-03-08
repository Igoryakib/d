#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* new_node = new Node;
        new_node->data = val;
        new_node->next = head;
        head = new_node;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void remove(int val) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value not found" << endl;
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void filteredList() {
        LinkedList L;
        auto start = high_resolution_clock::now(); 
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data % 2 == 0) {
                L.insert(temp->data);
            }
            temp = temp->next;
        }
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start); 

        cout << "Filtered List: ";
        L.display();
        cout << "Time taken by filteredList: " << duration.count() << " microseconds" << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 1000; ++i) {
        list.insert(i);
    }
    auto start = high_resolution_clock::now();
    for (int i = 1; i <= 1000; ++i) {
        list.remove(i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by filteredList: " << duration.count() << " microseconds" << endl;
    cout << "Original List: ";
    list.display();
}
