#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <vector>

#include "include/BigNumber.hpp"

int main() {
	std::ifstream input("input1");
	if(!input.good()) {
		throw std::runtime_error("Fehler beim oeffnen der Input-Datei");
	}

	std::vector<std::string> numbers;
	std::string tmp_str;
	while(std::getline(input, tmp_str)) {
		numbers.push_back(tmp_str);
	}

	BigNumber sumOfNumbers;
	for(std::string tmp : numbers) {
		sumOfNumbers += tmp;
	}
	std::cout << "Sum of the numbers : " << sumOfNumbers.getNumber() << '\n';

	std::cout << "10 first digits: ";
	for(unsigned short i = 0; i < 10; i++) {
		std::cout << sumOfNumbers.getNumber()[i];
	}
	std::cout << '\n';

	return 0;
}
