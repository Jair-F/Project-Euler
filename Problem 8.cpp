#include <iostream>
#include <fstream>
#include <vector>

#define NUMBERS_TO_CALCULATE 13

int main() {
	std::ifstream input("input");
	if(!input.good()) {
		std::cerr << "Fehler beim oeffnen der Input-Datei\n";
		return -1;
	}

	std::vector<char> numbers;
	{
		char c;
		while(! input.eof()) {
			input.get(c);
			if(c != '\n') {
				numbers.push_back(c);
			}
		}
	}
	
	std::size_t maxProduct = 0;

	for(unsigned short i = 0; i < numbers.size() - NUMBERS_TO_CALCULATE; i++) {
		std::size_t product = 1;

		for(unsigned short pos = 0; pos < NUMBERS_TO_CALCULATE; pos++) {
			product *= static_cast<char>(numbers[i + pos]) - '0';
		}
		if(product > maxProduct) {
			maxProduct = product;
		}
	}
	std::cout << maxProduct << '\n';

	return 0;
}