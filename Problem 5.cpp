#include <iostream>
#include <limits>

/*
    Aufgabe:

    2520 ist die kleinste Zahl, die ohne Rest durch jede der Zahlen von 1 bis 10 geteilt werdenkann.
    Was ist die kleinste positive Zahl, die durch alle Zahlen von 1 bis 20 gleichmäßig teilbar ist?
*/

bool teilbar_durch_1_bis_20(std::size_t zahl){
    for(int i{2}; i<=20; i++){
        if(zahl % i){
            return false;
        }
    }
    return true;
}

int main(){
    std::size_t i{1};
    std::cout << "Zahlen, die durch alle Zahlen von 1-20 teilbar sind:\n\t";
    while(i < std::numeric_limits<size_t>::max()){
        if(teilbar_durch_1_bis_20(i)){
            std::cout << i << ", ";
        }
        i++;
    }


    return 0;
}
