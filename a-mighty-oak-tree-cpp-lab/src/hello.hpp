#include <iostream>
#include <string>

using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }
};

template <typename T = Squirrel>
class Node {
private:
    T* data;
    Node<T>* left_child;
    Node<T>* right_child;
public:
    Node(T* data);

    void set_right(Node<T>* node);
    void set_left(Node<T>* node);
    Node<T>* left();
    Node<T>* right();
    T* get_data();
    void display();
};
template<typename T>
Node<T>::Node(T* data) {
    this->data = data;
    left_child = nullptr;
    right_child = nullptr;
}
template<typename T>
void Node<T>::set_left(Node<T>* node) {
    left_child = node;
}
template<typename T>
void Node<T>::set_right(Node<T>* node) {
    right_child = node;
}
template<typename T>
Node<T>* Node<T>::left() {
    return left_child;
}
template<typename T>
Node<T>* Node<T>::right() {
    return right_child;
}
template<typename T>
T* Node<T>::get_data() {
    return data;
}
template<typename T>
void Node<T>::display() {
    cout << data->get_name() << endl;
}