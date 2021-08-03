#include <iostream>
#include <string>
#include <vector>

/*
	Algorithmus:
		Habe schriftliches dividieren verwendet. Wenn die aktuelle Division und der Divident gleich sind wie ein früherer(schon gerechneter,
		im Log gespeicherter), dann haben wir eine Periode gefunden
*/

/**
 * To find a recurring we have to compare the past divident'ss with the actual divident and the past digit_divison's with the actual
 * digit_division. If both match we have catched a recursion!
 */
struct DivisionLogger {
	unsigned short digit_division;
	unsigned short divident;
};

std::string division(long long divident, long long divisor) {
	std::vector<DivisionLogger> number_division_logger;
	std::string ret;
	if(divisor == 0) {
		throw std::logic_error("Divisor was 0 at division!");
	}
	if(divident < 0 || divisor < 0) {
		ret += '-';
	}
	if(divisor > divident) {
		divident *= 10;
		ret += "0.";
	}

	while(divident > 0) {
		DivisionLogger tmp;
		if(divisor > divident) {
			ret += '0';
			tmp.divident = divident;
			tmp.digit_division = 0;
		} else {
			ret += std::to_string(divident / divisor);

			tmp.divident = divident;
			tmp.digit_division = divident/divisor;

			divident = divident % divisor;
		}
		number_division_logger.push_back(tmp);

		divident *= 10;

		for(std::size_t i = 0; i < number_division_logger.size(); ++i) {
			if(number_division_logger[i].digit_division == divident / divisor && number_division_logger[i].divident == divident) {	// We found a recurring
	
				ret.insert(i + 2, std::string("("));	// Add the bracket(recurring-sign) at the position of the number(+2 because we have the leading "0.")
				ret += ')';

				return ret;
			}
		}

	}
	return ret;
}

int main() {
	std::string longest_divison;
	int d;

	for(unsigned int i = 2; i < 1'000; ++i) {
		std::string tmp  = division(1, i);
		//std::cout << i << ": " << tmp << '\n';
		if(tmp.size() > longest_divison.size()) {
			longest_divison = tmp;
			d = i;
		}
	}

	auto i = longest_divison.begin();
	while(*i != '(') {	// Find begin of recurring
		++i;
	}
	++i;

	std::size_t counterRecurring = 0;
	while(*i != ')') {	// Counting size of recurring
		++i;
		++counterRecurring;
	}

	std::cout << longest_divison << '\n';
	std::cout << "Length of recurring: " << counterRecurring << '\n';
	std::cout << "Value: " << d << '\n';

	return 0;
}