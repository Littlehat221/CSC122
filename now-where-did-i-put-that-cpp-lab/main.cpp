#include <iostream>
#include <string>
#include "src/where.hpp"

int main() {
  std::string example = "This is Something unique, check tests for example outputs";
  std::cout << "For the string: " << example << "\nthe letter f is in index number " << find(example, 'f');
  std::cout << '\n' <<'\n';
  //add on one
  std::cout << "For the string: " << example << "\n the string 's som' (case insensitive) is in index number " << find(example, "s som",0,false);
  std::cout << '\n' <<'\n';
  //add one two
  std::cout << "For the string: " << "The quick brown fox" <<  "the letter 'e' is in index number " << find("The quick brown fox", 'e',2) << '\n';
  std::cout << "For the string: " << "The quick brown fox" <<  "the letter 'e' is in index number " << find("The quick brown fox", 'e',3)<< '\n';
  std::cout << "For the string: " << "The quick brown fox" << " the letter 'e' is in index number " << find("The quick brown fox", 'e',500)<< '\n';
  std::cout << '\n' <<'\n';
  //add on three
  std::cout << "For the string: " << "lamb" << " the case '*mb' is in index number " << find("lamb", "*mb")<< '\n';
  std::cout << "For the string: " << "dumb" << " the case 'b*' is in index number " << find("dumb", "b*")<< '\n';
  std::cout << '\n' <<'\n';
  //add one four
  std::cout << "For the string: " << "dumb bunnies" << " the thing *bunnies is in index number " << find("dumb bunnies","*bunnies")<< '\n';
  std::cout << "For the string: " << "dumb bunnies" << " the thing b*b*n is in index number " << find("dumb bunnies","b*b*n")<< '\n';
  std::cout << "For the string: " << "dumb bunnies" << " the thing b*n*nis in index number " << find("dumb bunnies","b*n*n")<< '\n';
  std::cout << "For the string: " << "dumb bunnies" << " the thing u*n*n is in index number " << find("dumb bunnies","u*n*n")<< '\n';

}
