#include <iostream>
#include <vector>
#include <limits>

// Aufgabe:
/*
    Die Primfaktoren von 13195 sind 5, 7, 13 und 29.
    Was ist der größte Primfaktor der Zahl 600851475143?
*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                                                          SOLVED
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool isPrime(long long x){                      // Funktion, die errechnet, ob der Parameter x eine Primzahl ist
    if(x < 2)                                   // Ueberpruefen, ob die Zahl kleiner als 2 ist(1, 0...). Wann es so ist, dann false zurueckgeben
        return false;
    for(size_t i=2; i<x; i++){                  // Alle Zahlen von 2 bis x-1 durchgehen und ueberpruefen,
        if(x % i == 0){                         // ob der Parameter durch eine Zahl, die kleiner wie er ist teilbar ist.
            return false;                       // Wenn eine Zahl die kleiner als er ist durch ihn teilbar ist, false zurueckgeben
        }
    }
    return true;                                // Alle moeglichkeiten wurden getestet, die Zahl ist eine Primzahl. true zurueckgeben
}
long long nextPrime(long long x){               // Funktion, die ein Parameter bekommt und die naechst hoehere Primzahl errechnet
    x++;                                        // Parameter um eins erhoehen, da die jetzige Zahl ja eine Primzahl sein koennte
    while(isPrime(x) == false){                 // Die Schleife laeuft so lange durch und erhoet x immer um 1, bis
        x++;                                    // x eine Primzahl ist.
    }
    return x;                                   // Es gibt dann x(die naechste Primzahl zurueck.
}

long long primfaktor(long long x, std::vector<long long>& primfaktoren){// Funktion, die dein naechsten Primfaktor der Zahl x errechnet, und ihn in dem Vector primfaktoren abspeichert und das Divisionsergebnix zurueckgibt
    long long teiler{2};                        // Kleinster Teiler ist 2. Mit ihm wird angefangen
    while(x % teiler){                          // Schleife laeuft so lange durch, bis x(Parameter) durch teiler Teilbar(Primzahl) ist.
        teiler = nextPrime(teiler);             // Wenn x nicht durch x(Parameter) nicht durch teiler(Primzahl) teilbar ist wird die naechste Primzahl ausprobiert(Funktion nextPrime)
    }
    x /= teiler;
    primfaktoren.push_back(teiler);             // Primfaktor wurde gefunden, wird im Vector primfaktoren abgespeichert
    return x;                                   // Divisionsergebnis(x) wird zurueckgegeben
}
void primfaktorteiler(long long x, std::vector<long long>& primfaktoren){// Funktion, die die Primfaktoren von x errechnet und in dem Vector Primfaktoren abspeichert
    long long tmp{x};                        // Temporaeres Objekt der Eingabe, dass Eingabe nacheher vielleicht noch verwendet werden kann
    while(isPrime(tmp) == false){               // Schleife laeuft so lange durch, bis tmp(Eingabe) eine Primzahl ist
        tmp = primfaktor(tmp, primfaktoren);    // Ruft eine Funktion auf, die den naechsten Primfaktor von tmp errechnet, ihn in dem Vector primfaktoren abschpeichert
    }                                           // und das Divisionsergebnis an tmp(Eingabe, veraendert) zurueckgibt.
    primfaktoren.push_back(tmp);                // Der Letzte Primfaktor ist das letzte Divisionsergebnis, das eine Primzahl ist.
}


int main(){
    std::cout << "Primfaktorzerlegung\n";
    std::cout << "Geben Sie bitte eine Zahl ein: ";
    long long eing;                             // Speichert die Eingabe des Benutzers
    std::cin >> eing;
    if(eing <= 1){                              // Eingabe darf nicht kleiner gleich 1 sein, da es sonst eine Endlosschleife gibt!
        std::cout << "--\n";
        std::cout << "Ungueltiget Eingabe. Die Zahl muss groesser als 1 sein!!\n";
        return -1;
    }else if(eing > std::numeric_limits<long long>::max()-1){// Eingabe darf nicht groesser als max von long sein
        std::cout << "Eingabe ist zu gross! Die Zahl darf max " << std::numeric_limits<long long>::max()-1 << " sein\n";
        return -1;
    }
    std::cout << "Primfaktorteiler von " << eing << " sind: ";
	if(isPrime(eing)){
		std::cout << "1 ";
	}

    std::vector<long long>primfaktoren;         // Vector, in dem die Primfaktoren gespeichert werden
    primfaktorteiler(eing, primfaktoren);       // Funktion, die die Primfaktoren errechnet und in dem Vector Primfaktoren abspeichert
    for(size_t i=0; i<primfaktoren.size(); i++){// Alle Elemente in dem Vector primfaktoren ausgeben
        std::cout << primfaktoren[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
