#include <iostream>
#include <chrono>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to print the linked list
    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Function to create a new linked list containing only odd elements from two input lists
LinkedList mergeOddElements(const LinkedList& s1, const LinkedList& s2) {
    auto start = std::chrono::high_resolution_clock::now();
    LinkedList s3; // Resultant list containing odd elements

    Node* temp1 = s1.head;
    Node* temp2 = s2.head;

    // Traverse both lists
    while (temp1 && temp2) {
        // Check if the current element in S1 is odd
        if (temp1->data % 2 != 0) {
            s3.insert(temp1->data);
        }

        // Check if the current element in S2 is odd
        if (temp2->data % 2 != 0) {
            s3.insert(temp2->data);
        }

        // Move to the next elements in S1 and S2
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Print execution time
    std::cout << "Execution time: " << duration.count() << " microseconds." << std::endl;
    return s3;
}

int main() {
    // Create two linked lists S1 and S2
    LinkedList S1, S2;

    for (int i = 0; i < 1000; i++) {
        S1.insert(i);
        S2.insert(++i);
    }


    // Print the original lists
    std::cout << "S1: ";
    S1.print();

    std::cout << "S2: ";
    S2.print();
    
    // Merge odd elements from S1 and S2 to form S3
    LinkedList S3 = mergeOddElements(S1, S2);

    // Print the merged list S3
    std::cout << "S3 (odd elements from S1 and S2): ";
    S3.print();

    return 0;
}