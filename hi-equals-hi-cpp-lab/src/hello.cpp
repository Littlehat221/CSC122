#include <string>
#include <algorithm>
#include <cctype>

int strcmp_case_insensitive(std::string CaseOne, std::string CaseTwo) {
   //preparing for case-insensitive without altering oringinal input strings
   std::string CaseOneTransform = CaseOne;
   std::string CaseTwoTransform = CaseTwo;
   std::transform(CaseOneTransform.begin(), CaseOneTransform.end(), CaseOneTransform.begin(),[](char c){ return std::tolower(c); });
   std::transform(CaseTwoTransform.begin(), CaseTwoTransform.end(), CaseTwoTransform.begin(),[](char c){ return std::tolower(c); });
   //checking for greater than, equal to, less than
   for (int x = 0; x < CaseOne.length() || x < CaseTwo.length(); x++) {
      if (CaseOneTransform[x] > CaseTwoTransform[x]) {
         return 1;
      }
      if (CaseOneTransform[x] < CaseTwoTransform[x]) {
         return -1;
      }
   }
   return 0;
}
