#include <iostream>

bool istTeilbar(unsigned int zahl, unsigned int teiler){
    if(zahl%teiler == 0){
        return true;
    }
    return false;
}

int main(){
    unsigned int sum{0};
    for(unsigned int i{1}; i<1000; i++){
        if(istTeilbar(i, 3) || istTeilbar(i, 5)){
            sum += i;
            std::cout << i << ", ";
        }
    }
    std::cout << "\nSumme: " << sum << '\n';

    return 0;
}
