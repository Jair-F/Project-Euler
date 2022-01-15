#include <iostream>
#include <list>

#include "include/BigNumber.hpp"

//#define DEBUG

std::string power(unsigned short num, unsigned short pow) {
    BigNumber ret("1");
    for(unsigned short i = 0; i < pow; i++) {
        ret *= num;
    }
    return ret.getNumber();
}

int main() {
    std::list<std::string> powers;
    
    for(unsigned short num = 2; num <= 100; ++num) {
        for(unsigned short pow = 2; pow <= 100; ++pow) {
            powers.insert(powers.end(), power(num, pow));

            #ifdef DEBUG
                auto lastElement = powers.end();
                --lastElement;

                std::cout << num << "^" << pow << "=" << *lastElement << '\n';
            #endif // DEBUG
        }
    }

    powers.sort();
    powers.unique();

    std::cout << powers.size() << '\n';

    #ifdef DEBUG
    for(auto it = powers.begin(); it != powers.end(); it++) {
        std::cout << *it << ',';
    }
    std::cout << '\n';
    #endif // DEBUG

    return 0;
}