#include <iostream>
#include <limits>

std::size_t power(std::size_t num, unsigned short pow) {
	if(pow > 1) {
		return num * power(num, pow - 1);
	}
	return num;
}

/*
 * Da ich weiss, dass "194979" die groesste Nummer ist, kann ich diese einsetzen.
 * Davor habe ich "std::numeric_limits<std::size_t>::max()", was extrem lange braucht!
 * -- Die Obergrenze kann man bestimmt ausrechnen --
 */

int main() {
	std::size_t sumOfEqualNums = 0;
	for(std::size_t i = 2; i < 194979 + 1; i++) {
		std::size_t tmp = i;
		std::size_t sumOfPowNums = 0;
		while(tmp > 0) {
			sumOfPowNums += power(tmp % 10, 5);
			tmp /= 10;
		}
		if(sumOfPowNums == i) {
			std::cout << i << '\n';
			sumOfEqualNums += i;
		}
	}
	std::cout << "sumOfEqualNums: " << sumOfEqualNums << '\n';

	return 0;
}