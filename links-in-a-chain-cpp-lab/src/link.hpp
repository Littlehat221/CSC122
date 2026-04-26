#include <string>

class Link {
  private:
    std::string material;

  public:
    Link(std::string material);
    std::string get_material();
};

class Node {
private:
  Link* data;
  Node* child;
public:
  Node(Link* data);
  Node(Link* data, Node* parent);

  Link* get_data();
  Node* get_next();
  void attach(Node* next_node);
};