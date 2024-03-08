#include <iostream>
#include <stdexcept>
#include <chrono>

struct CustomArray {
    int* data;
    int capacity;
    int size;

    CustomArray(int initialCapacity = 10) {
        capacity = initialCapacity;
        data = new int[capacity];
        size = 0;
    }

    
    ~CustomArray() {
        delete[] data;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        // Shift elements to the left to overwrite the element to be removed
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        // Decrement size
        --size;
    }
    
    void insert(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = value;
    }

    
    int getSize() const {
        return size;
    }

    
    CustomArray copyAndFilterEvenNumbers() const {
        auto start = std::chrono::high_resolution_clock::now();

        CustomArray result(size); 

        for (int i = 0; i < size; ++i) {
            if (data[i] % 2 == 0) {
                result.insert(data[i]);
            }
        }

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken to filter even numbers: " << duration.count() << " microseconds" << std::endl;

        return result;
    }
};

int main() {
    CustomArray arr;

    
    for (int i = 1; i <= 1000; ++i) {
        arr.insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i <= 1000; ++i) {
        arr.removeAt(i);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken to filter even numbers: " << duration.count() << " microseconds" << std::endl;

    CustomArray evenNumbersArray = arr.copyAndFilterEvenNumbers();

    
    std::cout << "Even numbers in the new array: ";
    for (int i = 0; i < evenNumbersArray.getSize(); ++i) {
        std::cout << evenNumbersArray.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
