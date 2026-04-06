#include <iostream>
#include <thread>
#include "src/timer.hpp"

using namespace std;

int main() {
  Timer timer;
  //add one two
  Timer t1,t2;

  cout << "starting timers" << endl;
  timer.start();

  //sleep
  this_thread::sleep_for(chrono::seconds(3));

  timer.stop();
  cout << "elapsed seconds: " << timer.elapsed() << endl;
  //add on one
  timer.pretty_print();
  //add on two
  t1.start();
  this_thread::sleep_for(chrono::seconds(2));
  t1.stop();

  t2.start();
  this_thread::sleep_for(chrono::seconds(1));
  t2.stop();

  Timer sum = t1.add(t2);
  Timer diff = t1.subtract(t2);

  cout << "sum: ";
  sum.pretty_print();

  cout << "difference: ";
  diff.pretty_print();

  return 0;
}