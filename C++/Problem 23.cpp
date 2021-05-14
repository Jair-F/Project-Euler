#include <iostream>
#include <vector>
#include <list>

#define UPPER_LIMIT 28123 // The given "upper limit". All greater numbers can be written as sum of two abundant numbers.

// !!! ----- requires a lot of memory(over 700MB) ----- !!!

bool isProperDivisor(std::size_t num, std::size_t divisor) {
	return num % divisor == 0;
}

std::size_t sumOfProperDivisors(std::size_t num) {
	std::size_t sum_of_proper_divisors = 1; // Every number is divisable by 1 - add this number straigth and start in for-loop at 2
	for(std::size_t i = 2; i < num / 2 + 1; i++) { // The biggest proper divisor is num / 2(half of the number) - to be shure we half the number and add 1 to be shurely above the biggest limitQ
		if(isProperDivisor(num, i)) {
			sum_of_proper_divisors += i;
		}
	}
	return sum_of_proper_divisors;
}

bool isPerfectNumber(std::size_t num) {
	return sumOfProperDivisors(num) == num;
}

bool isAbundantNumber(std::size_t num) {
	return sumOfProperDivisors(num) > num;
}

bool isDeficientNumber(std::size_t num) {
	return sumOfProperDivisors(num) < num;
}

int main() {
	std::size_t sum_of_integers = 0; // Sum of all integers from 1 to 28123
	for(unsigned short i = 0; i <= UPPER_LIMIT; i++) {
		sum_of_integers += i;
	}
	std::cout << "Sum of all integers(1-28123): " << sum_of_integers << '\n';

	std::vector<std::size_t> abundant_numbers;

	// Calculate all abundant numbers under the "given" limit(28123)
	for(std::size_t i = 1; i <= UPPER_LIMIT; i++) {
		if(isAbundantNumber(i) == true) {
			abundant_numbers.push_back(i);
		}
	}

	// All Numbers which can be written as sum of two abundant numbers(from 1 to 28123)
	std::list<std::size_t> sum_of_two_abundant_numbers;

	// 2-te for schleif "j = i" -->
	// Man muss nicht nochmal durch alle elemente durchlaufen, man hat sie ja schon in vorigen durchlaeufen behandelt - 
	// z.B. am anfang 1 - 28123, dann 2 - 28123 am ende nur noch 28122 - 28123
	// bei i = 28122 hat man ja die vorigen nummern schon behandelt - es fehlen nur noch dir nummern j > i && j <= UPPER_LIMIT
	// ----> Grosse Performance-Verbesserung, da viel weniger Durchlaeufe gemacht werden muessen!!
	for(unsigned short i = 0; i < abundant_numbers.size(); ++i) {
		for(unsigned short j = i; j < abundant_numbers.size(); ++j) {
			sum_of_two_abundant_numbers.insert(sum_of_two_abundant_numbers.end(), abundant_numbers[i] + abundant_numbers[j]);
		}
	}

	sum_of_two_abundant_numbers.sort();
	sum_of_two_abundant_numbers.unique();

	// Subtract the numbers which can be written as sum of two abundant numbers from the sum of all numbers form 1 to 29123
	for(auto it = sum_of_two_abundant_numbers.begin(); it != sum_of_two_abundant_numbers.end(); ++it) {
		if(*it <= UPPER_LIMIT) {
			sum_of_integers -= *it;
		}
	}	

	std::cout << "Sum of all positive integers which cannot be written as sum of 2 abundant numbers(1-28123): " << sum_of_integers << '\n';

	return 0;
}