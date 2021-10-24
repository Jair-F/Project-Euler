#include <string>

#ifndef _BIG_NUMBER_HPP_INCLUDED_
#define _BIG_NUMBER_HPP_INCLUDED_

// string umdrehen - von hinten nach vorne
std::string stringFromBack(std::string& str) {
	std::string ret;
	for(int i = str.size() - 1; i >= 0; i--) {
		ret += str[i];
	}
	str.swap(ret);
	return str;
}

/*
	Only for positive and real(int) numbers

	Implemented basic +,* and equalation(==,>,<...) operators on string basis.
	It uses 'written calculation' like we learned in the 1'st - 4'th grade!
	This allows us to calculate bigger numbers than the normal int or long long can calculate.
	We are only limited at the RAM and the CPU!

	Of course this is a bit slower than calculating with int's of long long's but its not so limited
	by its max-size/number!
*/
class BigNumber {
private:
	std::string number;
public:
	BigNumber(std::string num="0") :number(num) { }
	BigNumber(std::size_t num) : number(std::to_string(num)) { }
	~BigNumber() { }
	void setNumber(std::string& num) { number = num; }
	std::string getNumber() const { return number; }

	BigNumber& operator+=(std::size_t numToAdd);
	BigNumber& operator+=(std::string numToAdd);
	BigNumber& operator+=(const BigNumber& Bn);

	BigNumber& operator*=(const BigNumber& bg);
	BigNumber& operator*=(unsigned long num);
	BigNumber operator*(unsigned long num);
	BigNumber operator*(const BigNumber& bg);

	const bool operator==(const std::string num) { return this->number == num; }
	const bool operator==(const BigNumber& bg) { return this->number == bg.getNumber(); }

	const bool operator>(std::string numToComp);
	const bool operator>(const BigNumber& bg) { return *this > bg.getNumber(); }
	const bool operator<(const std::string& numToComp) { return !(*this > numToComp); }
	const bool operator<(const BigNumber& bg) { return *this < bg.getNumber(); }
	const bool operator<=(const BigNumber& bg) { return *this < bg || *this == bg; }

	// Prefix
	BigNumber& operator++() {
		*this += 1;
		return *this;
	}
	// Postfix
	BigNumber operator++(int) {
		BigNumber oldNumber = *this;
		*this += 1;
		return oldNumber;
	}

	/*
	BigNumber& operator=(BigNumber& bg) { *this = bg.getNumber(); }
	BigNumber& operator=(std::string num) { number = num; return *this; }
	BigNumber& operator=(std::size_t num) { *this = std::to_string(num); }
	*/
};

const bool BigNumber::operator>(std::string numToComp) {
	std::string thisNumber = stringFromBack(this->number);
	stringFromBack(numToComp);
	char oneDigitNumToComp;
	char oneDigitThisNum;
	for(long i = (thisNumber.size() > numToComp.size() ? thisNumber.size() : numToComp.size()); i > 0; i--) {
		if(numToComp.size() < i) {
			oneDigitNumToComp = '0';
		} else {
			oneDigitNumToComp = numToComp[i - 1];
		}
		if(thisNumber.size() < i) {
			oneDigitThisNum = '0';
		} else {
			oneDigitThisNum = thisNumber[i - 1];
		}
		if(oneDigitThisNum < oneDigitNumToComp) {
			return false;
		}
	}
	return true;
}

BigNumber BigNumber::operator*(const BigNumber& bg) {
	if(this->number == "0" || bg.getNumber() == "0") {
		return BigNumber("0");
	}
	BigNumber ret(0);
	for(BigNumber i(0); i < bg; ++i) {
		ret += *this;
	}
	return ret;
}

BigNumber BigNumber::operator*(std::size_t num) {
	std::string orginalNumber = this->getNumber();
	BigNumber ret("0");
	for(std::size_t i = 0; i < num; i++) {
		ret += orginalNumber;
	}
	return ret;
}

BigNumber& BigNumber::operator*=(const BigNumber& bg) {
	for(BigNumber i("0"); i < bg; ++i) {
		*this += bg;
	}
	return *this;
}

BigNumber& BigNumber::operator*=(unsigned long num) {
	*this *= num;
	return *this;
}

BigNumber& BigNumber::operator+=(std::size_t numToAdd) {
	return *this += std::to_string(numToAdd);
}

BigNumber& BigNumber::operator+=(const BigNumber& Bn) {
	return *this += Bn.getNumber();
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

#endif // _BIG_NUMBER_HPP_INCLUDED_
