#include "NumberList.h"
#include <iostream>

void NumberList::Init(){
	this->count=0;
}

bool NumberList::Add(int x){
	if(this->count>=10)
		return false;
	this->numbers[count++]=x;
	return true;
}

void NumberList::Sort(){
	for(int i=1;i<this->count;i++){
		int val=this->numbers[i],j=i-1;
		while(j>=0 && this->numbers[j]>val){
			this->numbers[j+1]=this->numbers[j];
			j--;
		}
		this->numbers[j+1]=val;
	}
}
void NumberList::Print(){
	for(int i=0;i<this->count;i++)
		std::cout<<this->numbers[i]<<' ';
	std::cout<<'\n';
}
