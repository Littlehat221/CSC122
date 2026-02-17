#include <iostream>

#include "src/hello.hpp"

int main() {
  std::printf("The comparison of \"String one\" and \"string two\" returns %i.\n",strcmp_case_insensitive("String one","string two"));
  std::printf("The comparison of \"String one\" and \"string one\" returns %i.\n",strcmp_case_insensitive("String one","string one"));
  std::printf("The comparison of \"String two\" and \"string one\" returns %i.\n",strcmp_case_insensitive("String two","string one"));
  return 0;
}
