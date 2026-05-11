#include <iostream>
#include "src/hello.hpp"

using namespace std;

int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node<Squirrel> node_one(&cheeks);
    Node<Squirrel> node_two(&squeaks);
    Node<Squirrel> node_three(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    Node<Squirrel>* retrieved_node_one = node_one.left();
    Node<Squirrel>* retrieved_node_two = node_one.right();

    cout << "Left Child: ";
    retrieved_node_one->display();

    cout << "Right Child: ";
    retrieved_node_two->display();
}