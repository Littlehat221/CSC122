#include <iostream>
#include "src/link.hpp"


int main() {
  Link gold = Link("Gold");
  Node* node_one = new Node(&gold);

  Link silver = Link("Silver");
  Node* node_two = new Node(&silver, node_one);

  Link bronze = Link("Bronze");
  Node* node_three = new Node(&bronze, node_two);

  Node* retrieved_node_two = node_one->get_next();
  Node* retrieved_node_three = node_two->get_next();

  std::cout << "Traversing the list:" << std::endl;

  Node* current = node_one;

  while (current != nullptr) {
    std::cout << current->get_data()->get_material() << std::endl;
    current = current->get_next();
  }
}