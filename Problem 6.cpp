#include <iostream>
#include <vector>

/*
Aufgabe:
	Die Summe der Quadrate der ersten zehn natürlichen Zahlen ist,
					1² + 2² + ... + 10² = 385
	Das Quadrat der Summe der ersten zehn natürlichen Zahlen ist,
				(1 + 2 + ... + 10)² = 55² = 3025
	Daher beträgt die Differenz zwischen der Summe der Quadrate der ersten zehn natürlichen
	Zahlen und dem Quadrat der Summe 3025 - 385 = 2640.
	Ermitteln Sie die Differenz zwischen der Summe der Quadrate der ersten hundert
	natürlichen Zahlen und dem Quadrat der Summe.
*/

long long potenz(unsigned long number, unsigned int potenz){
	long long tmp{number};
	for(size_t i=potenz-1; i<potenz; i++){
		tmp = tmp * number;
	}
	return tmp;
}

int main(){
	unsigned int summe_von_potenzen{0};
	unsigned int summe_von_potenz_von_summen{0};
	for(unsigned short i{0}; i<=100; i++){
        summe_von_potenz_von_summen += i;
	}
	summe_von_potenz_von_summen = potenz(summe_von_potenz_von_summen, 2);
	for(unsigned short i{0}; i<=100; i++){
        summe_von_potenzen += potenz(i, 2);
	}
	std::cout << "Differenz zwischen " << summe_von_potenz_von_summen << " und " << summe_von_potenzen << " ist "
        << summe_von_potenz_von_summen-summe_von_potenzen << '\n';

	return 0;
}
