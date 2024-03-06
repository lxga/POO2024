#include "NumberList.h"
#include <iostream>

int main(){
    NumberList l;
    l.Init();//initializeaza lista
    std::cout<<"Scrie numerele din lista: ";
    
    int x;
    while(std::cin>>x){
        if(!l.Add(x)){//push_back(x)
            std::cout<<"Lista este plina!";
            break;
        }
    }
    
    l.Sort();//sorteaza lista
    l.Print();//afiseaza lista + new line

    return 0;
}