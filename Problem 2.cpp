#include <iostream>


int main(){
    unsigned int term1{1};
    unsigned int term2{2};
    std::size_t sum{0};
    while(term1 < 4'000'000 && term2 < 4'000'000){
        unsigned int tmp_term{term1+term2};
        term1 = term2;
        term2 = tmp_term;
        if(term1 % 2 == 0){
            sum += term1;
        }
    }
    if(term2 % 2 == 0){
        sum += term1;
    }
    std::cout << sum << '\n';

    return 0;
}
