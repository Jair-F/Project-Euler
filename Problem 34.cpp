#include <iostream>

unsigned short fakul(unsigned short num) {
	if(num > 1) {
		return num * fakul(num - 1);
	}
	return 1;	// 0! is also 1
}

int main() {
	std::size_t sum_curios_numbers = 0;

	// I took randomly this number(9999999) as upper limit and dont calculated it - it worked
	for(std::size_t i = 3; i <= 9999999; i++) {
		// We need to store the actual number in an extra variable, because we extract every digit and need to modify the number
		std::size_t tmp = i;
		std::size_t sum_of_factofial_digits = 0;
		// extract all the digits of the number and calculate the faculty from them - and sum that up
		while(tmp > 0) {
			sum_of_factofial_digits += fakul(tmp % 10);
			tmp /= 10;
		}
		if(sum_of_factofial_digits == i) {
			sum_curios_numbers += i;
		}
	}

	std::cout << "Sum: " << sum_curios_numbers << '\n';

	return 0;
}