#include <iostream>
#include <chrono>

// Dynamic array structure
struct DynamicArray {
    int* data;
    size_t size;
    size_t capacity;

    // Constructor
    DynamicArray() : data(nullptr), size(0), capacity(0) {}

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Function to insert a new element at the end of the array
    void insert(int value) {
        // Check if capacity needs to be increased
        if (size >= capacity) {
            // Double the capacity
            capacity = (capacity == 0) ? 1 : capacity * 2;

            // Allocate new memory
            int* newData = new int[capacity];

            // Copy existing elements
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            // Delete old memory
            delete[] data;

            // Update data pointer
            data = newData;
        }

        // Insert new element
        data[size++] = value;
    }

    // Function to print the array
    void print() {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Function to create a new array containing only odd elements from two input arrays
DynamicArray mergeOddElements(const DynamicArray& arr1, const DynamicArray& arr2) {
    DynamicArray result; // Resultant array containing odd elements

    size_t size1 = arr1.size;
    size_t size2 = arr2.size;
    size_t index1 = 0, index2 = 0;

    // Traverse both arrays
    while (index1 < size1 && index2 < size2) {
        // Check if the current element in arr1 is odd
        if (arr1.data[index1] % 2 != 0) {
            result.insert(arr1.data[index1]);
        }

        // Check if the current element in arr2 is odd
        if (arr2.data[index2] % 2 != 0) {
            result.insert(arr2.data[index2]);
        }

        // Move to the next elements in arr1 and arr2
        ++index1;
        ++index2;
    }

    return result;
}

int main() {
    // Create two dynamic arrays arr1 and arr2
    DynamicArray arr1, arr2;

    for (int i = 0; i < 1000; i++) {
        arr1.insert(i);
        arr2.insert(++i);
    }

    // Print the original arrays
    std::cout << "arr1: ";
    arr1.print();

    std::cout << "arr2: ";
    arr2.print();
    auto start = std::chrono::high_resolution_clock::now();
    // Merge odd elements from arr1 and arr2 to form result
    DynamicArray result = mergeOddElements(arr1, arr2);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Print the merged array result
    std::cout << "result (odd elements from arr1 and arr2): ";
    result.print();

    // Print execution time
    std::cout << "Execution time: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
