#include <iostream>

#include "include/BigNumber.hpp"

//#define DEBUG

int main() {
	BigNumber lastNumber("1");		// First term
	BigNumber actualNumber("1");	// Second term
	//										|
	std::size_t index = 2;	//			<----
	while(actualNumber.getNumber().size() < 1'000) {
		#ifdef DEBUG
			std::cout << lastNumber.getNumber() << '+' << actualNumber.getNumber() << '=';
		#endif // DEBUG
		BigNumber tmp = actualNumber;
		actualNumber += lastNumber;
		lastNumber = tmp;
		#ifdef DEBUG
			std::cout << actualNumber.getNumber() << '\n';
		#endif // DEBUG
		++index;
	}

	std::cout << '\n';

	std::cout << "Index: " << index << "\nNumber: " << actualNumber.getNumber() << '\n';
	return 0;
}