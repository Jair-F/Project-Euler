#include <iostream>
#include <vector>

bool IsProperDivisor(long number, long divisor) { return number % divisor == 0; }

struct NumProperDivisors {
	unsigned short number;
	std::vector<unsigned short> properDivisors;
	std::size_t sumOfProperDivisors = 0;
};
bool operator!=(NumProperDivisors &npd1, NumProperDivisors &npd2) { return npd1.number != npd2.number || npd1.properDivisors != npd2.properDivisors || npd1.sumOfProperDivisors != npd2.sumOfProperDivisors; }
std::ostream& operator<<(std::ostream& os, NumProperDivisors& npd) {
	os << "Number: " << npd.number << '\n';
	os << "Proper Divisors: ";
	for(auto num : npd.properDivisors) {
		os << num << ' ';
	}
	os << "\nSum of Proper Divisors: " << npd.sumOfProperDivisors << '\n';
	return os;
}

std::vector<NumProperDivisors> amicableNumbers;
std::vector<NumProperDivisors> Nums;
std::size_t sumOfAmicableNumbers = 0;

void calc(NumProperDivisors& npd) {
	for(unsigned short divisor = 1; divisor < npd.number; divisor++) {
		if(IsProperDivisor(npd.number, divisor)) {
			npd.properDivisors.push_back(divisor);
		}
	}

	for(auto num : npd.properDivisors) {
		npd.sumOfProperDivisors += num;
	}
}

bool alreadyCalculated(unsigned short number) {
	for(unsigned short i = 0; i < amicableNumbers.size(); i++) {
		if(number == amicableNumbers[i].number) {
			return true;
		}
	}
	return false;
}

int main() {
	NumProperDivisors actualNumber;
	NumProperDivisors lastNumber;

	for(unsigned short number = 0; number < 10'000; number++) {
		if(alreadyCalculated(number)) {
			continue;
		}
		actualNumber.number = number;
		calc(actualNumber);

		lastNumber = actualNumber;
		actualNumber = NumProperDivisors();
		actualNumber.number = lastNumber.sumOfProperDivisors;
		
		calc(actualNumber);

		if(actualNumber.sumOfProperDivisors == lastNumber.number && lastNumber.number != actualNumber.number) {
			amicableNumbers.push_back(lastNumber);
			amicableNumbers.push_back(actualNumber);
		}
		
		actualNumber = NumProperDivisors();
	}

	std::cout << "amicable Numbers: ";
	for(unsigned short i = 0; i < amicableNumbers.size(); i++) {
		std::cout << amicableNumbers[i] << '\n';
	}

	for(NumProperDivisors npd : amicableNumbers) {
		sumOfAmicableNumbers += npd.number;
	}

	std::cout << "Sum of Amicable Numbers: " << sumOfAmicableNumbers << '\n';
	return 0;
}