#include <string>
#include <iostream>

int find(std::string input, std::string want) {
    if (want.length() == 0) {
        return 0;
    }
    //example word: cat. Need to find: at. Where to start index
    for (int i = 0; i <= input.length() - want.length(); i++) {
        bool match = true;
        //check one by one
        for (int j = 0; j < want.length(); j++) {
            if (input[i+j] != want[j]) {
                match = false;
                break;
            }
        }
        if (match == true) {
            return i;
        }
    }
    return -1;
}
int find(std::string input, char want) {
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == want)
            return i;
    }
}
