#include <iostream>
#include <math.h>

/*
    Ein pythagoreisches Triplett ist eine Menge von drei natürlichen Zahlen, a < b < c , für die
                                 2     2    2
                                a  +  b  = c
                  2   2                 2
    Zum Beispiel 3 + 4 = 9 + 16 = 25 = 5
    Es gibt genau ein pythagoreisches Triplett, für das a + b + c = 1000 ist.
    Finden Sie das Produkt abc
*/

/*
    Notwendige Funktionen:
        > Funktion, die mir die Wurzel einer Zahl zurueckgibt.
                                 2
        > Funktion, die mir das c  von a und b zurueckgibt.
*/

std::size_t satz_pythagoras(std::size_t a, std::size_t b){
    return a*a + b*b;
}

int main(){

    long double a;
    long double b;
    long double c;

    for(std::size_t i{1}; i<=1000; i++){
        for(std::size_t j{1}; j<=1000; j++){
            a = i;
            b = j;
            c = sqrt(satz_pythagoras(a, b));
            //std::cout << "a:" << a << ' ' << "b:" << b << ' ' << "c:" << c << '\n';
            if(a+b+c == 1000 && a<b && b<c){
                std::cout << "a: " << a << '\n';
                std::cout << "b: " << b << '\n';
                std::cout << "c: " << c << '\n';
                std::cout << "a+b+c = " << a << '+' << b << '+' << c << " = " << a+b+c << '\n';
                std::size_t erg = a*b*c;
                std::cout << "a*b*c = " << a << '*' << b << '*' << c << " = " << erg << '\n';
                return 0;
            }
        }
    }

    return 0;
}
