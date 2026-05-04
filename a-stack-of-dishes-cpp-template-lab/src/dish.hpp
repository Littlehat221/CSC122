#include <iostream>
#include <stdexcept>
#include <string>

class Dish {
private:
  std::string description;

public:
  Dish(std::string description);
  std::string get_description();
};

template <typename T = Dish>
class DishStack {
private:
  static const int MAX_SIZE = 10;
  T* data[MAX_SIZE];
  int current_size;

public:
  DishStack();
  void push(T& element);
  T pop();
  T peek();
  int size();
  void clear();
  bool isFullCheck();
  bool isEmptyCheck();
};

template <typename T>
DishStack<T>::DishStack() {
  current_size = 0;

  for (int i = 0; i < MAX_SIZE; i++) {
    data[i] = nullptr;
  }
}

template <typename T>
void DishStack<T>::push(T& element) {
  if (isFullCheck()) {
    std::cout << "Stack is full" << std::endl;
    return;
  }

  data[current_size] = &element;
  current_size++;
}

template <typename T>
T DishStack<T>::pop() {
  if (isEmptyCheck()) {
    throw std::runtime_error("Stack is empty. Could not pop element.");
  }

  current_size--;
  T popped_element = *data[current_size];
  data[current_size] = nullptr;

  return popped_element;
}

template <typename T>
T DishStack<T>::peek() {
  if (isEmptyCheck()) {
    throw std::runtime_error("Stack is empty. Could not peek at element.");
  }

  return *data[current_size - 1];
}

template <typename T>
int DishStack<T>::size() {
  return current_size;
}

template <typename T>
void DishStack<T>::clear() {
  for (int i = 0; i < MAX_SIZE; i++) {
    data[i] = nullptr;
  }

  current_size = 0;
}

template <typename T>
bool DishStack<T>::isFullCheck() {
  return current_size == MAX_SIZE;
}

template <typename T>
bool DishStack<T>::isEmptyCheck() {
  return current_size == 0;
}

