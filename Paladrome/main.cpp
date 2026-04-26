#include <iostream>
#include <string>

int stringLength(std::string str) {
	if (str == "") {
		return 0;
	}
return 1 + stringLength(str.substr(1));
}

void generateString(char collection[], int n, int length, std::string current) {
	if (current.length() == length) {
		std::cout << current << std::endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		generateString(collection, n, length, current + collection[i]);
	}
}
void printAllStrings(char collection[], int n, int k)
{
	generateString(collection, n, k, "");
}
int main() {
	std::string string1 = "goo";
	std::string string2 = "googoogaagaa";

	char collection1[] = {'a', 'b'};
	char collection2[] = {'a', 'b', 'c', 'd'};

	std::cout << stringLength(string1) << std::endl;
	std::cout << stringLength(string2) << std::endl;

	printAllStrings(collection1, std::size(collection1), 3);
	printAllStrings(collection2, std::size(collection2), 1);
}