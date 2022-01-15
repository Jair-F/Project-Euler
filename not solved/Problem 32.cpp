#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool is_pandigital(std::string number) {
    unsigned short number_occoured[10] = {0}; // 0-9 - 10
    for(char digit : number) {
        number_occoured[digit - '0'] += 1;
    }
    for(unsigned short i = 1; i < 9; ++i) { // We dont count the 0
        if (number_occoured[i] != 1)
            return false;
    }
    return true;
}

int main() {
    // 98'765'432
    std::vector<unsigned long> pandigital_products;
    for(unsigned long check_product = 1; check_product <= 98'765'432/2; ++check_product) {
        for (unsigned long multiplicand = 1; multiplicand <= check_product/2+1; ++multiplicand) {
            if(check_product % multiplicand == 0) { // if they are divedable
                unsigned long multiplier = check_product / multiplicand;
                std::string number = std::to_string(check_product) + std::to_string(multiplicand) + std::to_string(multiplier);
                if(is_pandigital(number)) {
                    if(std::find(pandigital_products.begin(), pandigital_products.end(), check_product) == pandigital_products.end()) {
                        pandigital_products.push_back(check_product);
                    }
                }
            }
        }
    }

    std::cout << "Num of pandigital Numbers: " << pandigital_products.size() << '\n';
    /*
    std::cout << "Pandigital Numbers:\n";
    for(unsigned int num : pandigital_products) {
        std::cout << num << '\n';
    }
    */
    std::cout << "\n\n";
    
   std::size_t sum = 0;
   for(unsigned long num : pandigital_products) {
       sum += num;
   }
   std::cout << "Sum of pandigital Numbers: " << sum << '\n';


    std::cout << "Fertig\n";

    return 0;
}