#include <iostream>
/*

*/
#define TEST
unsigned int punkte=3;

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
