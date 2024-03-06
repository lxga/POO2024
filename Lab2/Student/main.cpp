#include <iostream>

int main(){
    Student s1,s2;

    char s[51];
    std::cout<<"Introdu nume student 1: ";
    std::cin>>s;
    s1.setName(s);

    std::cout<<"Introdu nume student 2: ";
    std::cin>>s;
    s2.setName(s);

    float a,b,c;
    std::cout<<"Introdu note student 1(mate engleza istorie): ";
    std::cin>>a>>b>>c;
    s1.setmathGrade(a);
    s1.setenglishGrade(b);
    s1.sethistoryGrade(c);

    std::cout<<"Introdu note student 2(mate engleza istorie): ";
    std::cin>>a>>b>>c;
    s2.setmathGrade(a);
    s2.setenglishGrade(b);
    s2.sethistoryGrade(c);

    
}