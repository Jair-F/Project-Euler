#include <iostream>
#include <vector>
//#include <limits>

bool teilbar_durch_2(auto zahl){
    if((zahl > 1) && (zahl % 2 == 0)){
        return true;
    }
    return false;
}

auto durch_2_teilen(auto zahl){
    return zahl/2;
}

auto mal_3_plus_1(auto zahl){
    return zahl*3+1;
}
//1'000'000
int main(){
    std::vector<unsigned int> max_terme_zahlen;
    unsigned int terme{1};
    unsigned int zahl{1};
    unsigned int max_terme{0};
    for(; zahl <= 1'000'000; zahl++,terme=0){
        std::vector<unsigned int> tmp;
        unsigned int tmp_zahl=zahl;
        for(;tmp_zahl > 1;terme++){
            tmp.push_back(tmp_zahl);
            if(teilbar_durch_2(tmp_zahl)){
                tmp_zahl = durch_2_teilen(tmp_zahl);
            }
            else{
                tmp_zahl = mal_3_plus_1(tmp_zahl);
            }
        }tmp.push_back(tmp_zahl);
        if(terme > max_terme){
            max_terme = terme;
            max_terme_zahlen.clear();
            max_terme_zahlen = tmp;
        }
        tmp.clear();
    }
    for(unsigned int z{0}; z<max_terme_zahlen.size(); z++){
        std::cout << max_terme_zahlen[z];
        if(z+1 < max_terme_zahlen.size()){
            std::cout << ' ';
        }
    }
    std::cout << "\n\tDiese Operation benoetigte " << max_terme << " Terme\n";

    return 0;
}
