#include <iostream>

#include "src/point.hpp"

using namespace std;

int main() {

  Point p1 = Point(3.2, 9.8);
  Point p2 = Point(5.5, -1.2);

  cout << p1 - p2 << endl; // Prints out 11.238
  cout << (p1 == p2) << endl; // Prints out 0 (false)
  cout << (p1 != p2) << endl; // Prints out 1 (true)
  cout << p1 / p2 << endl; // Prints out a nicely formatted point such as (4.35, 4.3)
  //add on one
  Point p = Point(3.2, 9.8);
  cout << p * 2 << endl;   // This should print out (6.4, 19.6)
  cout << p * 2.0 << endl;   // This should print out (6.4, 19.6)
  cout << p * -3 << endl;   // This should print out (-9.6, -29.4)
  //add one two
  cout<< p['x']<<endl;   // my_x should be 3.2
  cout<< p['y']<<endl;   // my_y should be 9.8

}