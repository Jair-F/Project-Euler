#include <iostream>
#include <string>

#include "include/BigNumber.hpp"

BigNumber fakul(unsigned short number) {
	BigNumber ret("1");
	for(unsigned short i = number; i >= 2; i--) {
		ret = ret * i;
	}
	return ret;
}

int main() {
	std::string result = fakul(100).getNumber();
	std::cout << "Ergebnis: " << result << "\n\n";

	std::cout << "Summe der Zahlen: ";
	unsigned int sumOfDigits = 0;
	for(unsigned short i = 0; i < result.size(); i++) {
		sumOfDigits += result[i] - '0';
	}
	std::cout << sumOfDigits << '\n';


	return 0;
}
