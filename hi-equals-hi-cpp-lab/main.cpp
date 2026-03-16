#include <iostream>

#include "src/hello.hpp"

int main() {
  std::printf("The comparison of \"String one\" and \"string two\" returns %i.\n",strcmp_case_insensitive("String one","string two"));
  std::printf("The comparison of \"String one\" and \"string one\" returns %i.\n",strcmp_case_insensitive("String one","string one"));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("String two","string one"));
  std::cout << '\n';
  //add on one
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive(" My Cool String","mycoolstring",true));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("Another string","mycoolstring",true));
  std::cout << '\n';
  //add on two
  std::printf("The comparison of \"String one\" and \"string two\" returns %i.\n",strcmp_case_insensitive("String one","string two",false, 3));
  std::printf("The comparison of \"String one\" and \"string two\" returns %i.\n",strcmp_case_insensitive("String one","string two",false, 0));
  std::printf("The comparison of \"String one\" and \"string one\" returns %i.\n",strcmp_case_insensitive("String one","string one",false,-1));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("String two","string one",false,1000));
  std::cout << '\n';
  //add one three
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("2","50"));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("20","5"));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("100","100"));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("2 Some String","50 Some String"));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("20 Some String","5 Some String"));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("100 Some String","100 Some String"));
  return 0;
}
