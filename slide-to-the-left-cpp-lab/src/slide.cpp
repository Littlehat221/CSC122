#include <string>
#include <iostream>

#include "slide.hpp"

// Helper: normalize shifts
int fixer(int shifts, int size) {
   if (size == 0) {
      return 0;
   }
   shifts = shifts % size;
   if (shifts < 0) {
      shifts += size;
   }
   return shifts;
}

void arrayShiftLeft(int arr[], int size, int shifts) {
   shifts = fixer(shifts, size);

   for (int s = 0; s < shifts; s++) {
      int first = arr[0];

      for (int i = 0; i < size - 1; i++) {
         arr[i] = arr[i + 1];
      }

      arr[size - 1] = first;
   }
}

void arrayShiftRight(int arr[], int size, int shifts) {
   shifts = fixer(shifts, size);

   for (int s = 0; s < shifts; s++) {
      int last = arr[size - 1];

      for (int i = size - 1; i > 0; i--) {
         arr[i] = arr[i - 1];
      }

      arr[0] = last;
   }
}

// Vector version
void vectorShift(std::vector<int>& vec, int shifts) {
   int size = vec.size();
   shifts = fixer(shifts, size);

   for (int s = 0; s < shifts; s++) {
      int first = vec[0];

      for (int i = 0; i < size - 1; i++) {
         vec[i] = vec[i + 1];
      }

      vec[size - 1] = first;
   }
}
void printArray(int arr[], int size) {
   std::cout << "[";
   for (int i = 0; i < size; i++) {
      std::cout << arr[i];
      if (i != size - 1) std::cout << ", ";
   }
   std::cout << "]\n";
}