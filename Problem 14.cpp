#include <iostream>
#include <vector>

bool ist_gerade(std::size_t num) { return num % 2 == 0; }

//1'000'000
int main() {
	unsigned int numWithMaxTerms = 0;
	unsigned short maxTerms = 0;
	for(unsigned int i = 0; i < 1'000'000; ++i) {
		std::size_t tmpNum = i;
		std::size_t terms = 0;
		while (tmpNum > 1) {
			if(ist_gerade(tmpNum) == true) {
				tmpNum /= 2;
			} else {
				tmpNum *= 3;
				tmpNum += 1;
			}
			++terms;
		}
		if(terms > maxTerms) {
			maxTerms = terms;
			numWithMaxTerms = i;
		}
	}

	std::cout << "numWithMaxTerms: " << numWithMaxTerms << '\n';
	std::cout << "maxTerms: " << maxTerms << '\n';

	return 0;
}
