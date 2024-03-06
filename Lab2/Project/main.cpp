#include <cstdio>
#include "FirstClass.h"

int main(){
    FirstClass c1;
    c1.y=5;
    printf("Valoarea lui x este: %d\n",c1.getX());
    c1.setX(10);
    printf("Valoarea lui x este: %d\n",c1.getX());
    c1.setX(12);
    printf("Valoarea lui x este: %d\n",c1.getX());
    return 0;
}