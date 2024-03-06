#include "FirstClass.h"
int comparebyX(FirstClass *f1,FirstClass *f2){
	int a=f1->getX(),b=f2->getX();
	if(a<b)
		return -1;
	else if(a>b)
		return 1;
	else
		return 0;
}
