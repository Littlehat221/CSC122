#include <string>
#include "meet.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int* readCSV(const std::string& filename, int& size) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file.\n";
        size = 0;
        return nullptr;
    }

    int capacity = 10;
    int* data = new(std::nothrow) int[capacity];

    if (data == nullptr) {
        std::cerr << "Memory allocation failed.\n";
        size = 0;
        return nullptr;
    }

    size = 0;
    std::string line;

    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) {
            if (size == capacity) {
                capacity *= 2;
                int* temp = new(std::nothrow) int[capacity];

                if (temp == nullptr) {
                    delete[] data;
                    size = 0;
                    return nullptr;
                }

                for (int i = 0; i < size; i++) {
                    temp[i] = data[i];
                }

                delete[] data;
                data = temp;
            }

            data[size++] = std::stoi(value);
        }
    }

    return data;
}

double findMedian(const int* arr, int size) {
    if (size == 0) return 0;

    if (size % 2 == 1) {
        return arr[size / 2];
    } else {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}

double findMean(const int* arr, int size) {
    if (size == 0) return 0;

    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

int findMode(const int* arr, int size) {
    if (size == 0) return 0;

    int mode = arr[0];
    int maxCount = 1;
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}