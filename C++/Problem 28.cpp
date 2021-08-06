#include <iostream>
#include <vector>

/*
	When we create the Spiral:

	Field:
			7 8 9
			6 1 2
			5 4 3

	Number 1 is the middle(x = 0, y = 0)
	In this example we can go up(y < 0), down(y > 0), right(x > 0) and left(x < 0)

	let us define n as the number of rows and colums(in this example 3)

	When we create the spiral we go first 1 right, then down, then left, then up and then again right!

	Later this is unrelevant(if we already created the spiral), but for creating the spiral this imaginary "coordinate origin"
	is important!

*/

int main() {
	unsigned int fieldSize = 7;	// 5 Vertically and Horizontally

	std::cout << "FieldSize: ";
	std::cin >> fieldSize;

	if(fieldSize % 2 == 0) {	// Field-Size can not be an even number
		std::cerr << "Error: Field-Size cant be an even number!" << std::endl;
		exit(-1);
	}
	std::vector<std::vector<unsigned int>> field;


	// Creating the field
	field.resize(fieldSize);
	field.shrink_to_fit();

	for(auto& row : field) {
		row.resize(fieldSize);
		row.shrink_to_fit();
	}

	std::size_t assignNumberCounter = 1;

	std::size_t x_positon = field.size() / 2, y_position = field.size() / 2;

	field[y_position][x_positon] = assignNumberCounter++;

	// Initializen the field with values - read the top comment to understand how this works
	for(std::size_t circleNum = 0; circleNum < field.size() / 2; ++circleNum) {	// Every run through of this for loop is 1 circle in the spiral(in the example above from 2-9)

		// go 1 to the right(horizontally = x)
		field[y_position][++x_positon] = assignNumberCounter++;

		// go down(vertically = y)
		for(std::size_t i = 0; i < circleNum * 2 + 1; ++i) {
			field[++y_position][x_positon] = assignNumberCounter++;
		}
		
		// go to the left(horizontally = x)
		while(x_positon > field[y_position].size() / 2 - (circleNum + 1)) {
			field[y_position][--x_positon] = assignNumberCounter++;
		}

		// go up(vertically = y)
		while(y_position > field[y_position].size() / 2 - (circleNum + 1)) {
			field[--y_position][x_positon] = assignNumberCounter++;
		}

		// go to the right(horizontally = x)
		for(std::size_t i = 0; i < circleNum * 2 + 1; ++i) {
			field[y_position][++x_positon] = assignNumberCounter++;
		}

		field[y_position][++x_positon] = assignNumberCounter++;
		
		/*
		for(auto& colum : field) {
			for(auto& row : colum) {
				std::cout.width(3);
				std::cout.fill(' ');
				std::cout << row << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
		*/
	}

	// Calcuate sum of diagonal numbers
	std::size_t diagonalSum = 0;

	for(std::size_t i = 0; i < field.size(); ++i) {	// From left bottom to right top
		diagonalSum += field[i][(field.size() - 1) - i];
	}
	for(std::size_t i = 0; i < field.size(); ++i) {	// From left top to right bottom
		diagonalSum += field[i][i];
	}

	diagonalSum -= 1;	// Subtract 1 because we summed up the middle 2 times(the diagonals meet in the middle) and the middle is always 1

	std::cout << "diagonal-Sum: " << diagonalSum << '\n';

	char showField;
	std::cout << "Show the Field? Y/N ";
	std::cin >> showField;

	if(showField == 'y' || showField == 'Y') {
		for(auto& colum : field) {
			for(auto& row : colum) {
				std::cout.width(3);
				std::cout.fill(' ');
				std::cout << row << ' ';
			}
			std::cout << '\n';
		}
	}


	return 0;
}