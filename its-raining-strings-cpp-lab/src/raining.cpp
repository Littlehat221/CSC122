#include <string>
#include <vector>
#include <iostream>

void display(std::vector<std::string> current) {
    if (current.size() == 1)
        std::cout << "\nYour business is:\n\n";
    else
        std::cout << "\nYour businesses are:\n\n";
    for (int i = 0; i < current.size(); i++) {
        std::cout << "    " << current[i] << "\n";
    }
    return;
}
