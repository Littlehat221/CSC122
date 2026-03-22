#include <iostream>

#include "src/meet.hpp"

int main() {
  std::string filename;
  std::cout << "Enter the filename: ";
  std::cin >> filename;

  int size = 0;
  int* data = readCSV(filename, size);

  if (data == nullptr || size == 0) {
    std::cout << "No data loaded.\n";
    return 1;
  }

  bubbleSort(data, size);
  double median = findMedian(data, size);
  double mean = findMean(data, size);
  int mode = findMode(data, size);

  std::cout << "Median: " << median << "\n";
  std::cout << "Mean: " << mean << "\n";
  std::cout << "Mode: " << mode << "\n";

  delete[] data;
  return 0;
}