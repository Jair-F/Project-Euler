#include <iostream>
#include <vector>

/*
    Aufgabe:
    Die Folge der Dreieckszahlen wird durch Addition der natürlichen Zahlen erzeugt. So ist die
    7th würde Dreieck Zahl 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. Die ersten zehn Begriffe wären:
                    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
    Lassen Sie uns die Faktoren der ersten sieben Dreieckszahlen auflisten:
    1 : 1
    3 : 1,3
    6 : 1,2,3,6
    10 : 1,2,5,10
    15 : 1,3,5,15
    21 : 1,3,7,21
    28 : 1,2,4,7,14,28
    Wir können sehen, dass 28 die erste Dreieckszahl ist, die mehr als fünf Teiler hat.
    Was ist der Wert der ersten Dreieckszahl mit mehr als fünfhundert Teilern?
*/
template<typename T>
T dreieckszahlen(unsigned long zahl){
    T tmp{0};
    for(T i{1}; i<=zahl; i++){
        tmp += i;
    }
    return tmp;
}
template<typename T>
unsigned int teiler_einer_zahl(T zahl){
    unsigned int teiler{0};
    for(unsigned long i{1}; i<=zahl; i++){
        if((zahl % i) == 0){
            teiler++;
        }
    }
    return teiler;
}


int main(){
    std::cout << "Berechnung der kleinsten Dreieckszahl mit mehr als x Teiler\n\n";
    unsigned long zahl{1};
    std::size_t dreieckszahl;
    unsigned int teiler{0};
    unsigned short min_teiler{501};
    std::cout << "Geben Sie Bitte die Zahl der Teiler ein: ";
    std::cin >> min_teiler;
    std::cout << "Berechnung der kleinsten Dreieckszahl mit mehr als " << min_teiler << " Teiler wurde gestartet.\n";
    //std::cout << "Rechnen: ";
    while(teiler <= min_teiler){
        dreieckszahl = dreieckszahlen<std::size_t>(zahl);
        teiler = teiler_einer_zahl(dreieckszahl);
        //if((zahl%500) == 0){
        //    std::cout << '.';
        //}
        zahl++;
    }
    std::cout << "\nDie Zahl " << dreieckszahl << " ist die kleinste Dreiecks-Zahl, die mehr als " << min_teiler << " Teiler hat. Sie hat " << teiler << " Teiler.\n";

    return 0;
}
