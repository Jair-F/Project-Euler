#include <iostream>
/*

*/
#define TEST
// "Kreuzungen" der Linien(Bei 3x3 Grid sind es 4, bei 20x20 Grid sind es 21)
unsigned int punkte=21;

unsigned int gitterwege(unsigned int x=punkte, unsigned int y=punkte){
    if(x == 0 && y == 0){
        return 0;
    }
    if(x > y){
        return 1 + gitterwege(x-1, y);
    }else if(y == x){
        return 1 + gitterwege(x-1, y);
    }else{  // y > x
        return 1 + gitterwege(x, y-1);
    }
}

int main(){
    std::cout << gitterwege();

    return 0;
}
