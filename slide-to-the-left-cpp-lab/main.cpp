#include <iostream>

#include "src/slide.hpp"

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  arrayShiftLeft(arr1, 5, 1); // This would update arr1 to [2, 3, 4, 5, 1]
  printArray(arr1, 5);
  arrayShiftLeft(arr1, 5, 1); // This would update arr1 to [3, 4, 5, 1, 2]
  printArray(arr1, 5);
  arrayShiftLeft(arr1, 5, 1); // This would update arr1 to [4, 5, 1, 2, 3]
  printArray(arr1, 5);

  int arr2[] = {1, 2, 3, 4, 5};
  arrayShiftLeft(arr2, 5, 3); // This would update arr2 to [4, 5, 1, 2, 3]
  printArray(arr2, 5);
  arrayShiftLeft(arr2, 5, 3); // This would update arr2 to [2, 3, 4, 5, 1]
  printArray(arr2, 5);
  arrayShiftLeft(arr2, 5, 3); // This would update arr2 to [5, 1, 2, 3, 4]
  printArray(arr2, 5);

  int arr3[] = {1, 2, 3};
  arrayShiftLeft(arr3, 3, 3); // This would update arr3 to [1, 2, 3] (back to where it began)
  printArray(arr3, 5);

  arrayShiftLeft(arr3, 3, 4); // This would update arr3 to [2, 3, 1]
  printArray(arr3, 5);

  return 0;
}