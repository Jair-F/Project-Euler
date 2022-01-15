#include <iostream>

/*
	Indem wir die ersten sechs Primzahlen auflisten: 2, 3, 5, 7, 11 und 13, können wir sehen,
	dass die 6. Primzahl 13 ist.
	Was ist die 10 001. Primzahl?
*/
bool isPrime(size_t zahl){
	if(zahl < 2){
		return false;
	}
	for(size_t i{2}; i<zahl; i++){
		if(zahl%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	size_t primzahl_an_stelle{10'001};
	size_t tmp_primzahlen_stelle{0};
	size_t tmp{0};
	size_t hoechste_primzahl{0};
	while(tmp_primzahlen_stelle != primzahl_an_stelle){
		if(isPrime(tmp)){
			if(tmp > hoechste_primzahl){
				hoechste_primzahl = tmp;
			}
			tmp_primzahlen_stelle++;
		}
		tmp++;
	}
	std::cout << "Die Primzahl an der Stelle " << tmp_primzahlen_stelle << " ist " << hoechste_primzahl << '\n';
	return 0;
}