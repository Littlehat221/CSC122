#include <string>
#include <iostream>

class Cutie {
private:
  std::string description;
  int cuteness_rating;

public:
  Cutie(std::string description, int cuteness_rating);
  std::string get_description();
  int get_cuteness_rating();
};
class Puppy : public Cutie {
public:
  Puppy();
};
class Kitty : public Cutie {
public:
  Kitty();
};
class PygmyMarmoset : public Cutie {
public:
  PygmyMarmoset();
};

template <typename T = Cutie>
class QueueTees {
private:
  static const int MAX_SIZE = 3;
  T* data[MAX_SIZE];
  int start_index;
  int end_index;
  int current_size;
public:
  QueueTees();
  void enqueue(T& element);
  T* dequeue();
  int size();
  void clear();
  bool isFullCheck();
  bool isEmptyCheck();
};
template<typename T>
QueueTees<T>::QueueTees() {
  start_index = 0;
  end_index = 0;
  current_size = 0;

  for (int i = 0; i < MAX_SIZE; i++) {
    data[i] = nullptr;
  }
}

template<typename T>
void QueueTees<T>::enqueue(T& element) {
  if (isFullCheck()) {
    std::cout << "Queue is full" << std::endl;
    return;
  }
  else {
    data[end_index] = &element;
    end_index = (end_index + 1) % MAX_SIZE;
    current_size++;
  }
}

template<typename T>
T* QueueTees<T>::dequeue() {
  if (isEmptyCheck()) {
    std::cout << "Queue is empty" << std::endl;
    return nullptr;
  }
  else {
    T* removedElement = data[start_index];
    std::cout << "Removed element is " << removedElement->get_description() << std::endl;
    data[start_index] = nullptr;
    start_index = (start_index + 1) % MAX_SIZE;
    current_size--;
    return removedElement;
  }
}

template<typename T>
int QueueTees<T>::size() {
  return current_size;
}

template<typename T>
void QueueTees<T>::clear() {
  for (int i = 0; i < MAX_SIZE; i++) {
    data[i] = nullptr;
  }
  start_index = 0;
  end_index = 0;
  current_size = 0;
  return;
}

template<typename T>
bool QueueTees<T>::isEmptyCheck() {
  return current_size == 0;
}

template<typename T>
bool QueueTees<T>::isFullCheck() {
  return current_size == MAX_SIZE;
}

