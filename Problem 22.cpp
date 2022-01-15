#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

class Name{
public:
    Name(const char* n=""): name(n){
        if(elements == 0){
            prev = nullptr;
            next = nullptr;
        }
        this->elements++;
    }
    virtual~Name(){
        elements--;
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
    void push_back(const char* n=""){
        Name* tmp = this;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = new Name(n);
        tmp->next->next = nullptr;
        tmp->next->prev = tmp;
    }
    std::string* at(unsigned int pos){
        assert(pos<elements);
        Name* tmp = this;
        unsigned int tmp_pos{1};
        while(tmp_pos < pos){
            tmp_pos++;
            tmp = tmp->next;
        }
        return &(tmp->name);
    }
private:
    std::string name;
    static unsigned int elements;
    Name* next;
    Name* prev;
};

int main(){
    std::ifstream input("names.txt");
    std::vector<std::string>namens_liste;
    std::string name;
    char c;
    bool wort{false};
    while(input.get(c)){
        if(c=='"'){
            if(wort){
                wort=false;
                namens_liste.push_back(name);
                name.clear();
            }else{
                wort=true;
            }
        }
        else if(c>='A' && c<='Z' || c>='a' && c<='z'){
            name += c;
        }
    }
    std::size_t total{0};
    sort(namens_liste.begin(), namens_liste.end());
    for(unsigned int a{0}; a<namens_liste.size(); a++){
        std::string ausgabe = namens_liste[a];
        unsigned int tmp{0};
        for(unsigned int i{0}; i<ausgabe.size(); i++){
            if(ausgabe[i]>='a' && ausgabe[i]<='z'){
                tmp += ausgabe[i]-'a'+1;
            }
            else if(ausgabe[i]>='A' && ausgabe[i]<='Z'){
                tmp += ausgabe[i]-'A'+1;
            }
        }
        std::cout << ausgabe << ':' << tmp << '*' << a << '=';
        tmp *= (a+1);
        std::cout << tmp << '\n';
        total += tmp;
    }
    std::cout << "Summe von allen Zeichenzahlen: " << total << '\n';
    return 0;
}
