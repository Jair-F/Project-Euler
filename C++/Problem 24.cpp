#include <iostream>
#include <string>
#include <algorithm> // for std::sort

// Link to help how to logically generate permutations
// https://www.dcode.fr/permutations-generator

unsigned counter = 0;

/**
 * @param per the permutation which will be created
 * @param freeNumbers the numbers which we not alerady used
 */
void permutations(std::string per, std::string freeNumbers) {
	if(freeNumbers.size() > 0){
		for(unsigned short i = 0; i < freeNumbers.size(); i++) {
			std::string tmp = freeNumbers;
			auto number_to_remove = tmp.begin();
			number_to_remove += i;
			tmp.erase(number_to_remove);
			permutations(per + freeNumbers[i], tmp);
		}
	}
	else {
		// std::cout << per << '\n';
		counter++;
	}
	if(counter == 1'000'000) {
		std::cout << per << '\n';
		exit(0);	// If we have found the millionth permutation exit
	}
}

/**
 * @param items The items from which the permutations are created
 */
void print_permutations(std::string items) {
	std::unique(items.begin(), items.end());	// Remove duplicates
	std::sort(items.begin(), items.end());	// put the items in lexicograpic order. Later we need to have the items sorted
	permutations("", items);
}

int main() {
	print_permutations("1234567890");

	return 0;
}