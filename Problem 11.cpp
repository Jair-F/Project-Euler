#include <iostream>
#include <fstream>
#include <vector>

#define NUM_OF_ADJACENT_NUMBERS 4

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

int main() {
	std::ifstream input("input");
	if(!input) {
		std::cerr << "Fehler beim oeffnen der Input-Datei\n";
		return -1;
	}

	std::vector<std::vector<unsigned short>> grid;
	grid.push_back(std::vector<unsigned short>());
	grid[grid.size()-1].push_back(0);
	
	{
		char c;
		while(input.get(c)) {	// Read grid-input number by number
			if(isDigit(c)) {
				unsigned short& currentNumber = grid [grid.size() - 1] [grid[grid.size() - 1].size() - 1];
				
				currentNumber = c - '0';
				currentNumber *= 10;

				input.get(c);

				currentNumber += c - '0';
			} else if(c == ' ') {
				grid [grid.size() - 1].push_back(0);
			} else if(c == '\n') {
				grid.push_back(std::vector<unsigned short>());
				grid[grid.size()-1].push_back(0);
			}
		}

		grid.pop_back(); // Remove last vector - added because of eof()


	}

	for(auto vec : grid) {
		for(auto number : vec) {
			std::cout << number << ' ';
		}
		std::cout << '\n';
	}

	std::size_t maxProduct = 0;

	for(unsigned short y = 0; y < grid.size(); ++y) {	// Horizontal Lines
		for(unsigned short x = 0; x < grid[y].size(); ++x) {	// Vertikal Lines
			std::size_t tmpProduct = 1;
			
			// up - down
			if(x + NUM_OF_ADJACENT_NUMBERS < grid[y].size()) {
					for(unsigned short i = 0; i < NUM_OF_ADJACENT_NUMBERS; i++) {
						tmpProduct *= grid[y][x + i];
					}
					maxProduct = maxProduct > tmpProduct ? maxProduct : tmpProduct;
			}

			tmpProduct = 1;

			// left - right
			if(y + NUM_OF_ADJACENT_NUMBERS < grid.size()) {
					for(unsigned short i = 0; i < NUM_OF_ADJACENT_NUMBERS; i++) {
						tmpProduct *= grid[y + i][x];
					}
					maxProduct = maxProduct > tmpProduct ? maxProduct : tmpProduct;
			}

			tmpProduct = 1;

			// diagonal-natural
			if(x + NUM_OF_ADJACENT_NUMBERS < grid[y].size() && y + NUM_OF_ADJACENT_NUMBERS < grid.size()) {
					for(unsigned short i = 0; i < NUM_OF_ADJACENT_NUMBERS; i++) {
						tmpProduct *= grid[y + i][x + i];
					}
					maxProduct = maxProduct > tmpProduct ? maxProduct : tmpProduct;
			}

			tmpProduct = 1;

			{
				// diagonal-reverse
				unsigned short x_pos = x;					// X-Position is normal
				unsigned short y_pos = grid.size() - y - 1;	// Y-Position starts from down(-1, because grid.size() returns the number of the lines - we start counting from 0)
				if( (x_pos + NUM_OF_ADJACENT_NUMBERS) < grid[y_pos - NUM_OF_ADJACENT_NUMBERS].size() && (y_pos - NUM_OF_ADJACENT_NUMBERS) > 0 ) {
						for(unsigned short i = 0; i < NUM_OF_ADJACENT_NUMBERS; i++) {
							tmpProduct *= grid[y_pos - i][x_pos + i];
						}
						maxProduct = maxProduct > tmpProduct ? maxProduct : tmpProduct;
				}
			}
		}
	}
	std::cout << "maxProduct: " << maxProduct << '\n';
	return 0;
}