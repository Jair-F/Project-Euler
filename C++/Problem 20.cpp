#include <iostream>
#include <limits>
#include <string>
#include <cstring>

// string umdrehen - von hinten nach vorne
std::string stringFromBack(std::string& str) {
	std::string ret;
	for(int i = str.size() - 1; i >= 0; i--) {
		ret += str[i];
	}
	str.swap(ret);
	return str;
}

// Nur fuer positive und ganze zahlen
class BigNumber {
private:
	std::string number;
public:
	BigNumber(std::string num="") :number(num) { }
	~BigNumber() { }
	void setNumber(std::string& num) { number = num; }
	std::string getNumber() const { return number; }

	BigNumber& operator+=(std::string numToAdd);
	BigNumber operator*(unsigned long num);
	bool operator>(const std::string& numToComp);
	bool operator>(const BigNumber& bg) { return *this > bg.getNumber(); }
};

bool BigNumber::operator>(const std::string& numToComp) {
	char oneDigitNumToComp;
	char oneDigitThisNum;
	for(int i = (this->number.size() > numToComp.size() ? this->number.size() : numToComp.size()); i > 0; i--) {
		if(numToComp.size() < i) {
			oneDigitNumToComp = '0';
		} else {
			oneDigitNumToComp = numToComp[i];
		}
		if(this->number.size() < i) {
			oneDigitThisNum = '0';
		} else {
			oneDigitThisNum = this->number[i];
		}
		if(oneDigitThisNum > oneDigitNumToComp) {
			return true;
		}
	}
	return false;
}

BigNumber BigNumber::operator*(unsigned long num) {
	std::string orginalNumber = this->getNumber();
	BigNumber ret("0");
	for(unsigned long i = 0; i < num; i++) {
		ret += orginalNumber;
	}
	return ret;
}

// https://lehrerfortbildung-bw.de/u_matnatech/mathematik/bs/bej/bej1/grund/anl_add/
BigNumber& BigNumber::operator+=(std::string numToAdd) {	
	unsigned short uebertragen = 0;

	// Beide Strings umdrehen, da er dann vorne die einer,zehner... hat und es dadurch einfacher zu handhaben ist
	stringFromBack(this->number);
	stringFromBack(numToAdd);

	// wenn num laenger ist als this->number, this->number auf die gleiche laenge bringen(mit 0 auffuellen), da es nachher mindestens so lange ist!!
	if(numToAdd.size() > this->number.size()) {
		// Wie viele Stellen hinzugefuegt werden muessen muss vorher abgespeichert werden - this->number.size() aendert sich ja staendig
		int times = numToAdd.size() - this->number.size();
		for(unsigned int i = 0; i < times; i++) {
			this->number.push_back('0');
		}
	}

	for(unsigned int i = 0; i < this->number.size(); i++) {
	
		unsigned short this_number = this->number[i] - '0';
		unsigned short number_to_add = numToAdd.size() > i ? numToAdd[i] - '0' : 0;
		
		unsigned short result = this_number + number_to_add + uebertragen;
		if(result > 9) {
			this->number[i] = result % 10 + '0';
			uebertragen = result / 10;
		} else {
			this->number[i] = result + '0';
			uebertragen = 0;
		}
	}
	if(uebertragen > 0) {
		this->number.push_back(uebertragen % 10 + '0');
		uebertragen /= 10;
	}
	stringFromBack(this->number);
	return *this;
}

BigNumber fakul(unsigned short number) {
	BigNumber ret("1");
	for(unsigned short i = number; i >= 2; i--) {
		ret = ret * i;
	}
	return ret;
}

int main() {
	std::string result = fakul(100).getNumber();
	std::cout << "Ergebnis: " << result << "\n\n";

	std::cout << "Summe der Zahlen: ";
	unsigned int sumOfDigits = 0;
	for(unsigned short i = 0; i < result.size(); i++) {
		sumOfDigits += result[i] - '0';
	}
	std::cout << sumOfDigits << '\n';


	return 0;
}
