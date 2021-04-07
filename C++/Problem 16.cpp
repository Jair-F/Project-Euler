#include <iostream>
#include <string>

#include "include/BigNumber.hpp"

BigNumber power(std::size_t number, std::size_t pow) {
	BigNumber ret(std::to_string(number));
	for(std::size_t i = 0; i < pow - 1; i++) {
		ret = ret * number;
	}
	return ret;
}

int main() {
	std::string result = power(2, 1000).getNumber();
	std::cout << "Result: " << result << '\n';
	
	std::cout << "Sum of digits: ";
	std::size_t sumOfDigits = 0;
	for(char c : result) {
		sumOfDigits += c - '0';
	}
	std::cout << sumOfDigits << '\n';


	return 0;
}
