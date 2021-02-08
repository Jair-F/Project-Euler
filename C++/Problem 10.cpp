#include <iostream>
#include <limits>

/*
Die Summe der Primzahlen unter 10 ist 2 + 3 + 5 + 7 = 17.
Finden Sie die Summe aller Primzahlen unter zwei Millionen.
*/
bool isPrime(unsigned int zahl){
	if(zahl < 2){
		return false;
	}
	for(unsigned int i{2}; i<zahl; i++){
		if(zahl%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	std::size_t sum_of_primes{0};
	#define grenze 2'000'000
	std::cout << "Die Summe aller Primzahlen(von 0 bis " << grenze << ") ";
	for(unsigned int i{0}; i<grenze; i++){
		if(isPrime(i)){
			sum_of_primes += i;
		}
	}
	std::cout << "ist " << sum_of_primes << '\n';

	return 0;
}
