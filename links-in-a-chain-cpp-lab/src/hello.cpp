#include <string>
#include "link.hpp"

Link::Link(std::string material) {
    this->material = material;
}
std::string Link::get_material() {
    return this->material;
}

Node::Node(Link* data) {
    this->data = data;
    child = nullptr;
}
Node::Node(Link* data, Node* parent) {
    this->data = data;
    child = nullptr;
    parent->attach(this);
}

Link* Node::get_data() {
    return data;
}
Node* Node::get_next() {
    return child;
}
void Node::attach(Node* next_node) {
    child = next_node;
}