#include <iostream>
#include <string>


const char* digits[20] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
										"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char* teens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char* houndred = { "hundred" };
const char* thousend = { "thousand" };

// Only positive numbers
std::string printNumberInWords(unsigned short number) {
	// 1,2,3..9
	unsigned short singleNumbers = number % 10;
	// 10,20,30..90
	unsigned short tenNumbers = number % 100 - singleNumbers;
	// 100,200.300...900
	unsigned short houndreds = number % 1'000 - tenNumbers - singleNumbers;
	// 1'000...9'000
	unsigned short thousends = number % 10'000 - houndreds - tenNumbers - singleNumbers;


	std::string ret;

	if(thousends >= 1'000) {
		// !!two!! thousend, or !!three!! thousend, or !!ten!! thousend
		ret += digits[thousends / 1'000];
		ret +=' ';
		ret += thousend;
		ret += ' ';
	}

	if(houndreds >= 100) {
		ret += digits[houndreds / 100];
		ret +=' ';
		ret += houndred;
		ret += ' ';

		// If there is a lower number than hundred add the and. Example:
		//																	one hundred !!and!! ten
		//																	one thousand two hundred
		if(tenNumbers > 0 || singleNumbers > 0) {
			ret += "and";
			ret += ' ';
		}
	}

	if(tenNumbers >= 10 && tenNumbers < 20) {	// For eleven and twelve - otherwise it will give "ten one", "ten two"
		ret += digits[tenNumbers + singleNumbers];
		ret += ' ';
	} else if(tenNumbers >= 20) {	// For twenty thirty ...
		ret += teens[tenNumbers / 10];
		if(singleNumbers > 0){
			ret += '-';
		}
	}
	
	if(tenNumbers < 10 || tenNumbers >= 20) {	// If we dont have eleven, twelwe...
		ret += digits[singleNumbers];
	}

	return ret;
}

int main() {
	std::size_t sumOfLetters = 0;
	for(unsigned short i = 0; i <= 1'000; i++) {
		std::string number = printNumberInWords(i);
		for(unsigned short a = 0; a < number.size(); a++) {
			if(number[a] != ' ' && number[a] != '-') {
				++sumOfLetters;
			}
		}
		std::cout << i << " = " << number << '\n';
	}
	std::cout << "SumOfLetters: " << sumOfLetters << '\n';

	return 0;
}