#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>

bool isDigit(char c) { return c >= '0' && c <= '9'; }

std::size_t maxSum = 0;
std::vector<std::vector<unsigned short>> triangle;

void solveTriangle(unsigned short x_pos, unsigned short y_pos, std::size_t tmpSum = 0) {
	if(y_pos < triangle.size()) {
		unsigned short number = triangle[y_pos][x_pos];
		solveTriangle(x_pos + 1, y_pos + 1, tmpSum + number);
		solveTriangle(x_pos, y_pos + 1, tmpSum + number);
	} else {
		maxSum = tmpSum > maxSum ? tmpSum : maxSum;
	}
}

int main() {
	std::ifstream input("input");
	if(!input.good()) {
		throw std::runtime_error("Fehler beim oeffnen der Input-Datei!");
	}
	
	triangle.push_back(std::vector<unsigned short>());
	{ // Read Input-File
		char c;
		unsigned short currentNumber = 0;
		while(input.get(c)) {
			if(isDigit(c)) {
				currentNumber *= 10;
				currentNumber += c - '0';
			} else if(c == ' ') {
				triangle[triangle.size() - 1].push_back(currentNumber);
				currentNumber = 0;
			} else if(c == '\n') {
				triangle[triangle.size() - 1].push_back(currentNumber);
				currentNumber = 0;
				triangle.push_back(std::vector<unsigned short>());
			}
		}
		triangle.pop_back();
	}

	solveTriangle(0, 0);
	std::cout << "maxSum: " << maxSum << '\n';

	return 0;
}