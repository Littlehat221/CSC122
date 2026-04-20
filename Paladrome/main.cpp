#include <iostream>
#include <string>

double harmonic(int n) {
    if (n == 1) {
        return 1;
    }
    return (harmonic(n - 1) + (1 / n));
}

bool palindrome(std::string s) {
    if (s.length() <= 1) {
        return true;
    }
    if (s[0] != s[s.length() - 1]) {
        return false;
    }
    return palindrome(s.substr(1, s.length() - 2));
}
void triangle(int n) {
    if (n == 0) {
        return;
    }

    triangle(n - 1);
    for (int i = 0; i < n; i++) {
        std::cout << '*';
    }
    std::cout << std::endl;
}

int main() {
    std::cout << harmonic(5) << "\n\n";

    std::cout << palindrome("googoogaagaa") << '\n';
    std::cout << palindrome("lokikol") << "\n\n";

    triangle(10);
}