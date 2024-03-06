#include "NumberList.h"
#include <iostream>

int main(){
    NumberList l;
    l.Init();
    std::cout<<"Scrie numerele din lista: ";
    
    int x;
    while(std::cin>>x){
        if(!l.Add(x)){
            std::cout<<"Lista este plina!";
            break;
        }
    }
    
    l.Sort();
    l.Print();

    return 0;
}