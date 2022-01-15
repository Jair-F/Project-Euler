#include <iostream>
#include <string>
/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                                                SOLVED
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
/*
    Aufgabe:

    Eine palindromische Zahl liest sich in beide Richtungen gleich. Das größte aus dem Produkt
    zweier zweistelliger Zahlen hergestellte Palindrom ist 9009 = 91 × 99.
    Finden Sie das größte Palindrom, das aus dem Produkt zweier dreistelliger Zahlen besteht.
*/

long long umgekehrt(long zahl){
    long tmp = 0;
    long ret = 0;
    while(zahl>0){
        tmp = zahl/10;
        ret = ret + zahl - tmp*10;
        zahl/=10;
        if(zahl>0){
            ret *= 10;
        }
    }
    return ret;
}

int main(){
    int max_stellen;
    int max_zahl{0};
    std::cout << "Wie viele Stellen/Ziffern soll der hoechste Faktor haben: ";
    std::cin >> max_stellen;
    for(int i{0}; i<max_stellen; i++){
        max_zahl += 9;
        max_zahl *= 10;
    }max_zahl += 9;
    std::cout << "Maximale Zahl: " << max_zahl << '\n';
    max_zahl /= 10;
    long long max{0};
    int fak1{0};
    int fak2{0};
    for(long long i{0}; i<=max_zahl; i++){
        for(long long a{0}; a<=max_zahl; a++){
            if(umgekehrt(a*i) == a*i){
                if(a*i > max){
                    max = a*i;
                    fak1 = i;
                    fak2 = a;
                }
            }
        }
    }
    std::cout << fak1 << '*' << fak2 << '=' << max << '\n';

    return 0;
}
